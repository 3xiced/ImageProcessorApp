#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog.h"
#include "QStandardPaths.h"
#include "QImageReader.h"
#include "QImageWriter.h"
#include "QMessageBox.h"
#include "qradiobutton.h"
#include "Core/filtersettings.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openFileButton, &QPushButton::clicked,
            this, &MainWindow::open);
    connect(ui->tabWidget, &QTabWidget::currentChanged,
            this, &MainWindow::chooseFilter);
    connect(ui->contrastSlider, &QSlider::valueChanged,
            this, &MainWindow::processImageContrast);
    connect(ui->radioButton_2, &QRadioButton::toggled,
            this, &MainWindow::processImageGrayscale);
    connect(ui->radioButton, &QRadioButton::toggled,
            this, &MainWindow::processImagePlain);

    filterApplier = new Core::FilterApplier;

    contrastFilter = new Core::Filters::ContrastFilter;
    grayscaleFilter = new Core::Filters::GrayscaleFilter;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chooseFilter()
{
    int activeTabIndex = ui->tabWidget->currentIndex();
    if (activeTabIndex == 0) {
        layerFilterImage = { {0, nullptr} };
    }
}


void MainWindow::applyFilter(Core::IFilter * filter, Core::FilterSettings * additionalFilterSettings)
{
    if (!additionalFilterSettings)
        additionalFilterSettings = new Core::FilterSettings;
    filterApplier->setFilter(filter);

    QImage * image;
    int maxLayer = layerFilterImage.lastKey();
    bool isNewLayer = true;
    if (maxLayer == 0)
        image = &pm;
    else
    {
        QMap<Core::IFilter*, QImage*> * filterImage = layerFilterImage[maxLayer];
        if (filterImage->count(filter) == 1)
        {
            if (maxLayer == 1)
            {
                // Указатель на QImage для оригинального изображения
                image = &pm;
            }
            else
            {
                // Указатель на IFilter для предыдущего фильтра 
                Core::IFilter * key = layerFilterImage[maxLayer-1]->firstKey();
                // Указатель на QImage для предыдущего фильтра
                image = *(*layerFilterImage.find(maxLayer-1))->find(key);
            }
            isNewLayer = false;
        }
        else
        {
            // Указатель на IFilter активного фильтра|
            Core::IFilter * key = filterImage->firstKey();
            // Указатель на QImage для того фильтра, что сейчас активен
            image = *filterImage->find(key);
        }
        filterImage = nullptr;
    }

    Core::FilterSettings * filterSettings = additionalFilterSettings;
    // Копия image
    QImage image_ = (*image).copy();
    filterSettings->image = &image_;
    QImage * processedImage = filterApplier->processImage(filterSettings);
    delete filterSettings;

    ui->labelImageContainer->setPixmap(QPixmap::fromImage(*processedImage));
    ui->labelImageContainer->setScaledContents(true);

    if (isNewLayer)
        layerFilterImage.insert(maxLayer+1, new QMap<Core::IFilter*, QImage*> { {filter, new QImage(*processedImage)} });
    else
    {
        delete *layerFilterImage[maxLayer]->find(filter);
        delete layerFilterImage[maxLayer];
        layerFilterImage[maxLayer] =  new QMap<Core::IFilter*, QImage*> { {filter, new QImage(*processedImage)} };
    }
}

void MainWindow::removeFilter(Core::IFilter* filter)
{
    int maxLayer = layerFilterImage.lastKey();
    if (maxLayer == 0)
        return;

    bool found = false;
    for (int i = 1; i <= maxLayer; i++)
    {
        if (found) {
            auto it = layerFilterImage.find(i);
            layerFilterImage.erase(it);
            continue;
        }
        QMap<Core::IFilter*, QImage*>* filterImage = layerFilterImage[i];
        if (filterImage->count(filter) == 1) {
            found = true;
            auto it = layerFilterImage.find(i);
            layerFilterImage.erase(it);
        }
    }
    if (layerFilterImage.lastKey() != 0) {
        maxLayer = layerFilterImage.lastKey();
        QMap<Core::IFilter*, QImage*>* filterImage = layerFilterImage[maxLayer];
        // Указатель на IFilter активного фильтра
        Core::IFilter* key = filterImage->firstKey();
        // Указатель на QImage для того фильтра, что сейчас активен
        auto image = *filterImage->find(key);
        ui->labelImageContainer->setPixmap(QPixmap::fromImage(*image));
    }
    else {
        ui->labelImageContainer->setPixmap(QPixmap::fromImage(pm));
    }
    ui->labelImageContainer->setScaledContents(true);
}

void MainWindow::processImageContrast()
{
    Core::FilterSettings * filterSettings = new Core::FilterSettings();
    filterApplier->setFilter(contrastFilter);
    filterSettings->strenght = ui->contrastSlider->value();
    applyFilter(contrastFilter, filterSettings);
}

void MainWindow::processImageGrayscale()
{
    if (!ui->radioButton_2->isChecked())
        return;
    Core::FilterSettings * filterSettings = new Core::FilterSettings();
    filterApplier->setFilter(grayscaleFilter);
    filterSettings->strenght = ui->contrastSlider->value();
    applyFilter(grayscaleFilter, filterSettings);
}

void MainWindow::processImagePlain()
{
    if (!ui->radioButton->isChecked())
        return;
    removeFilter(grayscaleFilter);
    processImageContrast();
}

bool MainWindow::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull())
    {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                     .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }

    setImage(newImage);

    setWindowFilePath(fileName);
    return true;
}

void MainWindow::setImage(const QImage &image)
{
    pm = image;
    ui->labelImageContainer->setPixmap(QPixmap::fromImage(pm));
    ui->labelImageContainer->setScaledContents(true);
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog)
    {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
                                                  ? QImageReader::supportedMimeTypes()
                                                  : QImageWriter::supportedMimeTypes();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void MainWindow::open()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    layerFilterImage = { {0, nullptr} };

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first()))
    {
    }
}

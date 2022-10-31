#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Core/filterapplier.h"
#include "Core/ifilter.h"
#include "Core/Filters/grayscalefilter.h"
#include "Core/Filters/contrastfilter.h"
#include "Core/Filters/sobelfilter.h"
#include "Core/Filters/scharrfilter.h"
#include "Core/Filters/prewittfilter.h"
#include <QMultiMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void processImageContrast();
    void processImageGrayscale();
    void processImagePlain();
    void processImageSobel();
    void processImageScharr();
    void processImagePrewitt();
    void chooseFilter();
    bool loadFile(const QString &fileName);
    void setImage(const QImage &image);
    void open();
    void applyFilter(Core::IFilter * filter, Core::FilterSettings * additionalFilterSettings = nullptr);
    void removeFilter(Core::IFilter* filter);

private:
    typedef QMap<int, QMap<Core::IFilter*, QImage*>*> LayerFilterImage;
    Ui::MainWindow * ui;
    Core::FilterApplier * filterApplier;
    QImage pm;
    LayerFilterImage layerFilterImage;

    // Filters
    Core::Filters::GrayscaleFilter * grayscaleFilter;
    Core::Filters::ContrastFilter * contrastFilter;
    Core::Filters::SobelFilter * sobelFilter;
    Core::Filters::PrewittFilter* prewittFilter;
    Core::Filters::ScharrFilter* scharrFilter;
};
#endif // MAINWINDOW_H

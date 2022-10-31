/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *labelImageContainer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSlider *contrastSlider;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *saveFileButton;
    QPushButton *openFileButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(809, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(621, 581));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelImageContainer = new QLabel(groupBox);
        labelImageContainer->setObjectName(QStringLiteral("labelImageContainer"));
        labelImageContainer->setMinimumSize(QSize(601, 541));
        labelImageContainer->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelImageContainer);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(163, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(139, 445));
        tabWidget->setMaximumSize(QSize(139, 16777215));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tab_1->setMinimumSize(QSize(135, 415));
        verticalLayout_2 = new QVBoxLayout(tab_1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButton = new QRadioButton(tab_1);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(tab_1);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        contrastSlider = new QSlider(tab_1);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setMinimum(0);
        contrastSlider->setMaximum(10);
        contrastSlider->setSingleStep(1);
        contrastSlider->setValue(1);
        contrastSlider->setOrientation(Qt::Horizontal);
        contrastSlider->setInvertedAppearance(false);

        verticalLayout_2->addWidget(contrastSlider);

        verticalSpacer = new QSpacerItem(20, 317, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_3 = new QRadioButton(tab_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(tab_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_3->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(tab_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout_3->addWidget(radioButton_5);

        verticalSpacer_2 = new QSpacerItem(20, 339, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        saveFileButton = new QPushButton(groupBox_2);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setMinimumSize(QSize(131, 41));

        verticalLayout->addWidget(saveFileButton);

        openFileButton = new QPushButton(groupBox_2);
        openFileButton->setObjectName(QStringLiteral("openFileButton"));
        openFileButton->setMinimumSize(QSize(131, 41));

        verticalLayout->addWidget(openFileButton);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Image Contanier", nullptr));
        labelImageContainer->setText(QApplication::translate("MainWindow", "Plain image", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Options", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "Colored", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "Grayscale", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Contrast", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "\320\237\321\200\321\216\320\270\321\202\321\202", nullptr));
        radioButton_4->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\261\320\265\320\273\321\214", nullptr));
        radioButton_5->setText(QApplication::translate("MainWindow", "\320\251\320\260\321\200\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Gradient", nullptr));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save File", nullptr));
        openFileButton->setText(QApplication::translate("MainWindow", "Open File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

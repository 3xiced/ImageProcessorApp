QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Core/Filters/contrastfilter.cpp \
    Core/Filters/grayscalefilter.cpp \
    Core/Filters/prewitt.cpp \
    Core/Filters/scharr.cpp \
    Core/Filters/sobelfilter.cpp \
    Core/filterapplier.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Core/Filters/contrastfilter.h \
    Core/Filters/grayscalefilter.h \
    Core/Filters/prewitt.h \
    Core/Filters/scharr.h \
    Core/Filters/sobelfilter.h \
    Core/filterapplier.h \
    Core/filtersettings.h \
    Core/ifilter.h \
    filtersettings.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

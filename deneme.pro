QT       += core gui
QT += core gui serialport
QT += widgets serialport charts quick quickwidgets positioning location network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 release

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connectionsettingsdialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connectionsettingsdialog.h \
    mainwindow.h

FORMS += \
    connectionsettingsdialog.ui \
    mainwindow.ui \

TRANSLATIONS += \
    deneme_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc \
    resources.qrc

DISTFILES += \
    icons/usv.png \
    images/Background1.png

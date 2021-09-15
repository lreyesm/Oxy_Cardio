#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T10:20:54
#
#-------------------------------------------------

QT       += core gui serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Oximetro
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    bebe_data_class.cpp \
    qcustomplot.cpp \
    mythread_graph.cpp \
    globals.cpp

HEADERS += \
        mainwindow.h \
    bebe_data_class.h \
    qcustomplot.h \
    mythread_graph.h \
    globals.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    photos.qrc

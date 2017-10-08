#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T21:03:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = algorithmic_machines
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    models/modelbase.cpp

HEADERS  += mainwindow.h \
    models/modelbase.h

FORMS    += mainwindow.ui

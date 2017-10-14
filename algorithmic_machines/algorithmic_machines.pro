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
    models/modelbase.cpp \
    ui/Post/postcommandwidget.cpp \
    ui/basecommandwidget.cpp \
    factories/abstractfactory.cpp \
    factories/postfactory.cpp \
    models/modelpost.cpp \
    ui/Post/postworkareawidget.cpp \
    ui/baseworkareawidget.cpp \
    ui/Post/postcell.cpp

HEADERS  += mainwindow.h \
    models/modelbase.h \
    ui/Post/postcommandwidget.h \
    ui/basecommandwidget.h \
    factories/abstractfactory.h \
    factories/postfactory.h \
    models/modelpost.h \
    ui/Post/postworkareawidget.h \
    ui/baseworkareawidget.h \
    ui/Post/postcell.h

FORMS    += mainwindow.ui \
    ui/Post/postcommandwidget.ui \
    ui/Post/postworkareawidget.ui

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
    factories/AbstractFactory.cpp \
    factories/PostFactory.cpp \
    models/ModelBase.cpp \
    models/ModelPost.cpp \
    ui/Post/PostCell.cpp \
    ui/Post/PostCommandWidget.cpp \
    ui/Post/PostWorkAreaWidget.cpp \
    ui/BaseCommandWidget.cpp \
    ui/BaseWorkAreaWidget.cpp \
    MainWindow.cpp \
    ui/Post/PostCommandString.cpp \
    ui/BaseCommandString.cpp \
    models/Post/PostModelCommand.cpp \
    ui/CustomWidgets/LinkLineEdit.cpp

HEADERS  += \
    factories/AbstractFactory.h \
    factories/PostFactory.h \
    models/ModelBase.h \
    models/ModelPost.h \
    ui/Post/PostCell.h \
    ui/Post/PostCommandWidget.h \
    ui/Post/PostWorkAreaWidget.h \
    ui/BaseCommandWidget.h \
    ui/BaseWorkAreaWidget.h \
    MainWindow.h \
    ui/Post/PostCommandString.h \
    ui/BaseCommandString.h \
    models/Post/PostModelCommand.h \
    ui/MessageType.h \
    models/Post/PostCommandType.h \
    models/StatusPlay.h \
    ui/CustomWidgets/LinkLineEdit.h

FORMS    += \
    ui/Post/PostCommandWidget.ui \
    MainWindow.ui \
    ui/Post/PostWorkAreaWidget.ui

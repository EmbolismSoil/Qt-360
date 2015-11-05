#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T19:30:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = My360
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    closebutton.cpp \
    titlebar.cpp \
    centerwidget.cpp \
    basewidget.cpp \
    loginbutton.cpp \
    nunberwidget.cpp \
    fontwidget.cpp

HEADERS  += mainwindow.h \
    closebutton.h \
    titlebar.h \
    centerwidget.h \
    basewidget.h \
    loginbutton.h \
    nunberwidget.h \
    fontwidget.h

FORMS    +=

RESOURCES += \
    ../resource/img.qrc

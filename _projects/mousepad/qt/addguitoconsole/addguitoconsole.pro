#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T02:35:54
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = addguitoconsole
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    external/myserver.cpp \
    external/mythread.cpp

HEADERS  += mainwindow.h \
    external/myserver.h \
    external/mythread.h

FORMS    += mainwindow.ui

DISTFILES +=

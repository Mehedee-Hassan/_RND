QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = qtSocketProgrammng1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp \
    mythread.cpp

HEADERS += \
    myserver.h \
    mythread.h

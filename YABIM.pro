#-------------------------------------------------
#
# Project created by QtCreator 2016-02-24T14:16:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YABIM
TEMPLATE = app

CONFIG += C++11

SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    filter.cpp \
    imagedisplay.cpp \
    testfilter.cpp

HEADERS  += mainwindow.h \
    image.h \
    filter.h \
    imagedisplay.h \
    testfilter.h

FORMS    += mainwindow.ui

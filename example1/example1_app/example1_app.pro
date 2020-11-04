#-------------------------------------------------
#
# Project created by QtCreator 2016-10-06T10:53:51
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11 c++14
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = example1_app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

PROJNAME = example1_app
INSTTYPE = APP
include(RobotSDK_Main.pri)

#-------------------------------------------------
#
# Project created by QtCreator 2016-08-07T10:06:51
#
#-------------------------------------------------


QT       += widgets \
           core

TARGET = example1_module
TEMPLATE = lib

DEFINES += EXAMPLE1_MODULE_LIBRARY

SOURCES += example1_module.cpp

HEADERS += example1_module.h\
        example1_module_global.h
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \
-lopencv_flann

unix {
    target.path = /usr/lib
    INSTALLS += target
}

PROJNAME = example1_module
INSTTYPE = MOD
include(RobotSDK_Main.pri)

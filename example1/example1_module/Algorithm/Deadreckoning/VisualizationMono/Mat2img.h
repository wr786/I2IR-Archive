#ifndef MAT2IMG_H
#define MAT2IMG_H


#include <QtGui>
#include <QDebug>

#include <opencv2/opencv.hpp>

using namespace cv;

QImage cvMat2QImage(const Mat mat);

#endif // MAT2IMG_H

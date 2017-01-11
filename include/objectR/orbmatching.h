/*
 * 提取orb特征点描述用于物体识别
 */

#ifndef ORBMATCHING_H
#define ORBMATCHING_H

#include "objectR/base.h"

int orbmatching(const Mat src, Mat &result);
int objectrecognition(Mat img1, Mat img2, Mat &result);

#endif // ORBMATCHING_H

#ifndef SETTING_H
#define SETTING_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <cmath>

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/flann/flann.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/legacy/legacy.hpp"

#define PI 3.14159265358979323846
#define ChannelType int
#define HSV   0
#define HSV_H 1
#define HSV_S 2
#define HSV_V 3
#define BGR   4
#define BGR_B 5
#define BGR_G 6
#define BGR_R 7

extern float image_sizeRatio;
extern float blueCircle_thresholdRatio;
extern float marker_thresholdRatio;
	
namespace objectR
{	
	cv::Mat imageChannelSplit(cv::Mat img, ChannelType key);

	// get the position of destination
	void getPosition(const cv::Point2f p1, const cv::Point2f p2, cv::Point2f &ans); 		
}
#endif // SETTING_H






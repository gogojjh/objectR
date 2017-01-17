#ifndef DETECTMARKER_H
#define DETECTMARKER_H

#include "objectR/setting.h"
#include "objectR/DetectImage.h"

#include <sys/time.h>
#include <libv4l2.h>
#include <fcntl.h>
#include <errno.h>

#include <unistd.h>

#include "AprilTags/TagDetector.h"
#include "AprilTags/TagDetection.h"
#include "AprilTags/Tag16h5.h"
#include "AprilTags/Tag25h7.h"
#include "AprilTags/Tag25h9.h"
#include "AprilTags/Tag36h9.h"
#include "AprilTags/Tag36h11.h"

using namespace cv;
using namespace std;

namespace objectR
{
	class DetectMarker : public DetectImage
	{
	public:
		DetectMarker();
		DetectMarker(bool f, Mat img)
		{
			img_ = img.clone();
			f_ = f;
		}
		~DetectMarker();
		virtual void findObject();		
		void printResult();
		
		Mat img_;
		bool f_;
		vector<Point2f> markerCenters_;		
		vector<Eigen::Vector3d> translations_;
		vector<vector<double>> eulers_;
	};	
	
	class Marker
	{
	public:
		AprilTags::TagDetector *tagDetector_; // 提取的操作子
		AprilTags::TagCodes tagCodes_; // Apriltags 编码对应
		
		int width_;
		int height_;
		double tagSize_; // April tag的边长,meter为单位
		double fx_, fy_, cx_, cy_; // 相机内参, focal length and camera principal point
		bool timing;
		
		Marker();
		~Marker();
		void initialization(const Mat img);
		void processImage(Mat &img, 
							vector<Point2f> &markerCenter, 
							vector<Eigen::Vector3d> &translations, 
							vector<vector<double>> &eulers);
	};
		
		
		
		
}

#endif // DETECTMARKER_H






















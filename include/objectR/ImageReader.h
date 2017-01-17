#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>

#include "objectR/setting.h"
#include "objectR/DetectBlueCircle.h"
#include "objectR/DetectMarker.h"

using namespace cv;
using namespace std;

namespace objectR
{
	
	class ImageReader
	{
	public:
		ImageReader( std::string imagename)
		{
			img_original = imread(imagename);
			object_find = false;
		}
			
		~ImageReader();
		
		void changeImageSize()
		{
			resize(img_original, img_processed, Size(img_original.cols*image_sizeRatio, img_original.rows*image_sizeRatio));
		}
		
		void getImageSize(int &w, int &h)
		{
			w = img_original.cols;
			h = img_original.rows;
		}
		
		void executeBlueCircle()
		{
			bluecircle = new DetectBlueCircle(object_find, img_processed);
			bluecircle->findObject();
			bluecircle->printResult();
			object_find = bluecircle->f_;
			object_center.push_back(bluecircle->c_);
			img_processed = bluecircle->img_.clone();
		}
		
		void executeMarker()
		{
			marker = new DetectMarker(object_find, img_processed); // 识别二维码操作
			marker->findObject();
			marker->printResult();
			object_find = marker->f_;
			object_center = marker->markerCenters_;
			img_processed = marker->img_.clone();
		}
		
		void showOriginal()
		{
			namedWindow("Original image", CV_WINDOW_NORMAL);
			imshow("Original image", img_original);
		}
		
		void showResult()
		{
			namedWindow("Processed image", CV_WINDOW_NORMAL);
			imshow("Processed image", img_processed);
		}
		
	
		Mat getOriginal()
		{
			return img_original;
		}
		
		DetectBlueCircle *bluecircle;
		DetectMarker *marker;
		
		bool object_find;
		vector<Point2f> object_center;
		
	private:
		Mat img_original, img_processed;
	};
}
#endif // IMAGEREADER_H

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
			object_center = Point2f(-1, -1);
		}
			
		~ImageReader();
		
		void changeImageSize(float r)
		{
			resize(img_original, img_original, Size(img_original.cols*r, img_original.rows*r));
		}
		
		void getImageSize(int &w, int &h)
		{
			w = img_original.cols;
			h = img_original.rows;
		}
		
		void executeBlueCircle()
		{
			bluecircle = new DetectBlueCircle(object_find, object_center, img_original);
			bluecircle->findObject();
			object_find = bluecircle->f_;
			object_center = bluecircle->c_;
			img_processed = bluecircle->img_;
		}
		
		void executeMarker()
		{
			//marker = new DetectMarker(img_processed,  object_find, object_center);
			//marker->findObject();
		}
		
		void showOriginal()
		{
			imshow("Original image", img_original);
		}
		
		void showResult()
		{
			imshow("Processed image", img_processed);
		}
		
		void printResult()
		{
			cout << "If Find object = " << object_find << endl
				 << "Object center = x: " << object_center.x << " y: " << object_center.y << endl;
			waitKey(0);
		}
		
		Mat getOriginal()
		{
			return img_original;
		}
		
		DetectBlueCircle *bluecircle;
		DetectMarker *marker;
		
		bool object_find;
		Point2f object_center;
		
	private:
		Mat img_original, img_processed;
	};
}
#endif // IMAGEREADER_H

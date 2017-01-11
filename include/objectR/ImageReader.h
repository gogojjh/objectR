#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <opencv2/highgui/highgui.hpp>

#include "objectR/setting.h"
#include "objectR/DetectBlueCircle.h"
#include "objectR/DetectMarker.h"
#include <string>
#include <boost/concept_check.hpp>

using namespace cv;
using namespace std;

namespace objectR
{
	class ImageReader
	{
	public:
		ImageReader( std::string imagename);
		~ImageReader();
		void showOriginal()
		{
			imshow();
		}
		void showResult()
		{
			imshow();
		}
		void printResult()
		{
			
		}
		void sTransformer(const Mat image);

		DetectBlueCircle bluecircle;
		DetectMarker marker;

		Mat img_origin, img_processed;
		bool object_find;
		Point2f object_center;
	};
}
#endif // IMAGEREADER_H
reader->showOriginal();
		reader->showResult();
                reader->printResult();
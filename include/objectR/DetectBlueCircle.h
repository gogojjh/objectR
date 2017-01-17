#ifndef DETECTBLUECIRCLE_H
#define DETECTBLUECIRCLE_H

#include "objectR/setting.h"
#include "objectR/DetectImage.h"

using namespace cv;
using namespace std;

namespace objectR
{
	class DetectBlueCircle : public DetectImage
	{
	public:
		DetectBlueCircle() {}
		
		DetectBlueCircle(bool f, Mat img)
		{
			img_ = img.clone();
			f_ = f;
			c_.x = -1; c_.y = -1;
		}
			
		~DetectBlueCircle() {}
		
		virtual void findObject();	
		void printResult();
		
		Mat img_;
		bool f_;
		Point2f c_;
	};	
}

#endif // DETECTBLUECIRCLE_H

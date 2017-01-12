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
		
		DetectBlueCircle(bool f, Point2f c, Mat img)
		{
			img_ = img.clone();
			f_ = f;
			c_.x = c.x; c_.y = c.y;
		}
			
		~DetectBlueCircle() {}
		
		virtual void findObject();	
		
		Mat img_;
		bool f_;
		Point2f c_;
	};	
}

#endif // DETECTBLUECIRCLE_H

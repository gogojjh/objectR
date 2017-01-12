#ifndef DETECTMARKER_H
#define DETECTMARKER_H

#include "objectR/setting.h"
#include "objectR/DetectImage.h"

using namespace cv;
using namespace std;

namespace objectR
{
	class DetectMarker : public DetectImage
	{
	public:
		DetectMarker();
		~DetectMarker();
		virtual void findObject();		
	};	
}

#endif // DETECTMARKER_H

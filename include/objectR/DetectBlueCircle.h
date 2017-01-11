#ifndef DETECTBLUECIRCLE_H
#define DETECTBLUECIRCLE_H

#include "objectR/setting.h"
#include "objectR/DetectImage.h"

namespace ObjectR
{
	class DetectBlueCircle : public DetectImage
	{
	public:
		DetectBlueCircle();
		~DetectBlueCircle();
		virtual void findObject();		
	};	
}

#endif // DETECTBLUECIRCLE_H

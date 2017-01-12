#include "objectR/setting.h"
#include "objectR/ImageReader.h"

using namespace objectR;

int main()
{
        ImageReader *reader = new ImageReader("111.jpg");
	reader->changeImageSize(image_sizeRatio);
	reader->executeBlueCircle();
        if ( reader->object_find )
        {
		reader->showOriginal();
		reader->showResult();
                reader->printResult();
         }
         return 0;
}


 


#include "objectR/setting.h"
#include "objectR/ImageReader.h"

using namespace objectR;

int main()
{
        ImageReader *reader = new ImageReader("../image/destination.jpg");
	reader->changeImageSize();
	reader->executeMarker();
        if ( reader->object_find )
        {
		reader->showOriginal();
		reader->showResult();
		waitKey(0);
         }
         return 0;
}


 


#include "objectR/setting.h"
#include "objectR/ImageReader.h"

using namespace objectR;

int main()
{
        ImageReader *reader = new ImageReader("../image/destination.jpg");
	reader->changeImageSize();
	reader->executeMarker();
        if ( reader->object_find ) // 如果找到物体就展示原图和处理后的图
        {
		reader->showOriginal();
		reader->showProcessed();
		waitKey(0);
         }
         return 0;
}


 


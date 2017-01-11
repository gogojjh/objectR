#include "objectR/base.h"
#include "objectR/ImageReader.h"

int main()
{
        ImageReader *reader = new ImageReader(" ");
	
        if ( reader->object_find )
        {
		reader->showOriginal();
		reader->showResult();
                reader->printResult();
         }
}


 


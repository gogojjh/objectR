// different operation
#include "objectR/transformer.h"
#include "objectR/gridfourdetect.h"

Transformer::Transformer()
{
}

void Transformer::sTransformer(const Mat image)
{
    resize(image,img_Origin,Size(image.cols/IMAGE_SIZE_COL, image.rows/IMAGE_SIZE_ROW));
    img_Origin.copyTo(img_Result);
    center.x=img_Origin.cols/2;
    center.y=img_Origin.rows/2;

    // 将RGB图像的三个颜色通道分离存在与img_BGR中
    split(img_Origin,img_BGR);

    // 开操作
    Mat img_Open;
    Mat element = getStructuringElement( 0, Size( 2*open_size +3, 2*open_size+10 ), Point(open_size, open_size+5 ));
    morphologyEx( img_Origin, img_Open,MORPH_OPEN, element );
    split(img_Open,open_BGR);

    // 闭操作
    Mat img_Close;
    element = getStructuringElement( 0, Size( 2*close_size-5, 2*close_size-5 ), Point(close_size, close_size ) );
    morphologyEx( img_Origin, img_Close,  MORPH_CLOSE, element );
    split(img_Close,close_BGR);

    // canny边缘提取
    Canny(img_Origin, img_Canny, CANNY_THL, CANNY_THH);

}

Point Transformer::gCenter()
{
    Point p(center.x,center.y);
    return p;
}

Mat Transformer::gImage(int key)
{
    switch(key)
    {
        case 0: return img_Origin; break;
        case 1: return img_Canny; break;
        case 2: return img_Result; break;
    default: break;
    }
}

void Transformer::detectApriltag(Point2f &goal, float &distance, bool &find_object)
{
    markerdetect(img_Origin, goal, distance, find_object, img_Result, maskgrid);
}

void Transformer::detectFour(Point2f &goal, float &distance, bool &find_object)
{
    gridfourdetect(img_Origin, goal, distance, find_object, img_Result, maskgrid);
}


















#include "objectR/setting.h"
#include "objectR/DetectBlueCircle.h"

namespace objectR 
{
	void DetectBlueCircle::findObject()
	{
		Mat imgSingle = imageChannelSplit(img_, BGR_R);
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		float maxContourArea = 0;
		int maxContourArea_index = 0;

		//Mat element = getStructuringElement(MORPH_RECT,Size(27,27));
		//morphologyEx(imgSingle, imgSingle,MORPH_DILATE,element);
		//imshow("2_img_dilate",imgSingle);
		
		//medianBlur(imgSingle,imgSingle,5);

		//element = getStructuringElement(MORPH_RECT,Size(22,22));
		//morphologyEx(imgSingle,imgSingle,MORPH_ERODE,element);
		//imshow("3_img_close",imgSingle);

		//Mat element = getStructuringElement(MORPH_RECT,Size(5,5));
		//morphologyEx(imgSingle, imgSingle, MORPH_CLOSE, element);
		//imshow("img_single_close",imgSingle);

		//threshold(imgSingle, imgSingle, 60 , 255, THRESH_BINARY_INV );
		//imshow("img_single_threshold",imgSingle);

		findContours(imgSingle, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
		drawContours(imgSingle, contours, -1, Scalar(255), 2);
		imshow("contours",imgSingle);

		// Find the max area of contours
		for (int i=0;i<contours.size();i++)
		{
			int contourSize = contourArea(contours[i]);
			//cout<<"area"<<contourSize<<endl;
			if (contourSize < img_.cols * img_.rows * 0.066) continue;
			if (contourSize > maxContourArea)
			{
				maxContourArea = contourSize;
				maxContourArea_index = i;
			}
		}
		// cout << "Max area: " << maxContourArea << endl;

		RotatedRect box;
		if(maxContourArea != 0)
		{
			box = minAreaRect(contours[maxContourArea_index]);
			f_ = true;
		}
		
		Point2f vertex[4];
		box.points(vertex);

		for(int i=0;i<4;i++)    
		{
			line(img_, vertex[i], vertex[(i+1)%4], Scalar(0,0,255), 5);    //draw the rectangle of the box
		}
		c_.x = (vertex[1].x+vertex[3].x)/2;
		c_.y = (vertex[1].y+vertex[3].y)/2;
		Point2f center(img_.cols/2, img_.rows/2);
		circle(img_, c_, 3, Scalar(0,0,255), 2, 8, 0);
	}
	
	void DetectBlueCircle::printResult()
	{
		cout << "If Find object = " << f_ << endl
			<< "x = " << c_.x << " y = " << c_.y << endl;
	}

}



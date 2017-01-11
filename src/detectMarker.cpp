#include "objectR/base.h"
#include "objectR/markerdetect.h"

void markerdetect(const Mat src,
                Point2f &minG,
                float &minD,
                bool &minF,
                Mat &result,
                Mat &mask)
{
    src.copyTo(result);
    decectMarkerContour(src, minG, minD, minF, result);
}

/*
 * 提取二维码的黑色进行识别
 * 图像处理的步骤:
 * 去除图片的红色分量(红色滤波) -> 腐蚀操作 -> canny边缘提取 -> 寻找连通区域 ->
 * 寻找二维码的连通区域(像素面积>5000; 区域为凸多边形) -> 存储四个端点的
 */
void decectMarkerContour(const Mat src, Point2f &minG, float &minD, bool &minF, Mat &result)
{
    Mat img_h, img_threshold, morph_img;
    Mat img_canny(src.rows, src.cols,CV_8UC3,Scalar(0,0,0));

    img_h = colorConversion(src, BGR_R);
    threshold(img_h, img_threshold,60,255,1);

    Mat element = getStructuringElement(MORPH_RECT,Size(3,3));
    morphologyEx(img_threshold,img_threshold,MORPH_ERODE,element);

    Canny(img_threshold,img_canny,30,90);

    vector<vector<Point> > contours;
    vector<Point> approxCurve;
    vector<Vec4i> hierarchy;
    bool longEdge = 1;
    float markerArea = 0;
    bool sign_bigger = false;
    bool sign_small = false;
    Point2f pointsIn[4]={Point2f(0,0)};
    Point2f approxCenter(0,0);
    Point2f goal(0,0);
    Point2f center(src.cols/2, src.rows/2);

    findContours(img_canny, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    approxCurve.resize(contours.size());

    for(unsigned int i=0; i<contours.size();i++)
    {
        float contour_area=contourArea(contours[i]);
        if(contour_area>5000)
        {
            markerArea = contour_area;
            // 多边形逼近
            approxPolyDP(contours[i], approxCurve, double(contours[i].size()) * 0.05, true);
            // 判断连通区域是否为凸多边形
            if (isContourConvex(Mat(approxCurve)))
            {
                sign_bigger = true;
                int min_x = INT_MAX;
                int min_index = 0;
                // 计算中心坐标
                for(int j=0; j<4; j++)
                {
                    if(sqrt(approxCurve[j].x*approxCurve[j].x+approxCurve[j].y*approxCurve[j].y) < min_x)
                    {
                        min_x = sqrt(approxCurve[j].x*approxCurve[j].x+approxCurve[j].y*approxCurve[j].y);
                        min_index = j;
                    }
                }
                approxCenter.x = (approxCurve[1].x + approxCurve[3].x) / 2.0;
                approxCenter.y = (approxCurve[1].y + approxCurve[3].y) / 2.0;

                if (sqrt(pow(approxCenter.x - src.cols/2, 2.0) + pow(approxCenter.y - src.rows/2, 2.0)) < minD)
                {
                    getPosition(center, approxCenter, minG);
                    minD = sqrt(pow(approxCenter.x - src.cols/2, 2.0) + pow(approxCenter.y - src.rows/2, 2.0));
                    goal = approxCenter;
                }

                // 存储四个端点的坐标
                if(min_index == 0 )
                {
                    for(int j=0;j<4 ;j++)
                    {
                        pointsIn[j] = approxCurve[j];
                        circle(result,Point(pointsIn[j].x,pointsIn[j].y),3,Scalar(0,0,255));
                    }
                }
                else
                {
                    int array[] = {1, 2, 3, 0, 1, 2, 3};
                    size_t count=sizeof(array)/sizeof(int);
                    vector<int> tmp(array, array+count);
                    vector<int>::iterator tmp_itr = tmp.begin();
                    int k=0;
                    tmp_itr = find(tmp.begin(),tmp.end(),min_index);

                    for(;min_index!=0 && tmp_itr!=tmp.end() && k!=4;tmp_itr++)
                    {
                        pointsIn[k++] = approxCurve[*tmp_itr];
                        circle(result,Point(pointsIn[k-1].x,pointsIn[k-1].y),8,Scalar(0,0,255));
                    }
                }
            }
        }
        else if(sign_bigger = true && markerArea != 0 && 0.01*markerArea < contour_area && contour_area < 0.03*markerArea)
        {
            sign_small = true;
        }
        if(sign_bigger == true && sign_small == true)
        {
            Mat move_pos = markerPosition(img_h, pointsIn);
        }
    }
    circle(result, goal, 3, Scalar(0,0,255), 2);
}

/*
 * 计算相机相对于二维码的位姿, 解决PnP问题的参考代码
 */
Mat markerPosition(Mat &img, Point2f* pointsIn)
{
//    Mat img_out(400,400,CV_8UC1,Scalar(0,0,0));
//    Point2f pointsRes[4];
//    pointsRes[0] = Point2f(0, 0);
//    pointsRes[1] = Point2f(400 - 1, 0);
//    pointsRes[2] = Point2f(400 - 1, 400 - 1);
//    pointsRes[3] = Point2f(0, 400 - 1);

    // Size of the Marker, a standard marker
    vector<Point3f> objectPoints;
    objectPoints.push_back(Point3f(0,0,0));
    objectPoints.push_back(Point3f(410,0,0));
    objectPoints.push_back(Point3f(410,410,0));
    objectPoints.push_back(Point3f(0,410,0));

    vector<Point2f> imagePoints;
    for(int i=0;i<4;i++)
    {
        imagePoints.push_back(Point2f(pointsIn[i].x,pointsIn[i].y));
    }

    // 相机内参
    float tmp1[3][3] = {{1760.80462, 0, 929.95610}, {0, 1760.28449, 535.82561}, {0, 0, 1}};
    Mat cameMatrix(3,3,CV_32FC1, tmp1);

    // 畸变系数
    float tmp2[5] = {-0.41624, 0.23446, -0.00058, 0.00086, 0};
    Mat distCoeffs(1,5,CV_32F,tmp2);

    Mat rotat_vec(3,3,CV_32F), trans_vec(3,3,CV_32F);

    // PnP问题
    solvePnP(objectPoints, imagePoints, cameMatrix, distCoeffs, rotat_vec, trans_vec);

    // 变换矩阵
    //Mat transformMatrix = getPerspectiveTransform(pointsIn, pointsRes);
    //cout << transformMatrix << endl;

    // 输出旋转和平移矩阵
    // warpPerspective(img, img_out, transformMatrix, Size(400,400), cv::INTER_NEAREST);
    //  cout<<rotat_vec.col(0).row(0)<<endl;
    //  cout<<rotat_vec.at<double>(0,0)<<endl;
    //  cout<<"rotat_vec:"<<rotat_vec<<endl;
    //  cout<<"trans_vec:"<<trans_vec<<endl;
    // namedWindow("img_out");
    // imshow("img_out",img_out);
    return rotat_vec;
}

/*
Focal Length:          fc = [ 1760.80462   1760.28449 ] +/- [ 5.65463   5.71223 ]
Principal point:       cc = [ 926.95610   535.82561 ] +/- [ 6.68057   5.33905 ]
Skew:             alpha_c = [ 0.00000 ] +/- [ 0.00000  ]   => angle of pixel axes = 90.00000 +/- 0.00000 degrees
Distortion:            kc = [ -0.41624   0.23446   -0.00058   0.00086  0.00000 ] +/- [ 0.00756   0.03623   0.00048   0.00093  0.00000 ]
Pixel error:          err = [ 0.24291   0.15701 ]
*/

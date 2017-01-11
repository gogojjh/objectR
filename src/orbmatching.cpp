#include "objectR/orbmatching.h"

int orbmatching(const Mat src,
                            Mat &result)
{
    Mat img_octopus = imread("/home/gogojjh/QT/led/data/octopus.jpg");
    Mat img_hippo = imread("/home/gogojjh/QT/led/data/hippo.jpg");
    /*resize(img_mode1,img_mode1,Size(img_mode1.cols/3,img_mode1.rows/3),0,0,CV_INTER_LINEAR);
    resize(img_mode2,img_mode2,Size(img_mode2.cols/3,img_mode2.rows/3),0,0,CV_INTER_LINEAR);
    resize(img_src,img_src,Size(img_src.cols/3,img_src.rows/3),0,0,CV_INTER_LINEAR);*/
    //img_src = img_src - Scalar(100,100,100);
    //waitKey(0);
    int n_octopus = objectrecognition(img_octopus, src, result);
    //int n_hippo = objectrecognition(img_hippo, src, result);
    int n_hippo = 0;
    if ( n_octopus > n_hippo )
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int objectrecognition(Mat img1, Mat img2, Mat &result)
{
    //img2.copyTo(result);
    int n = 0;
    ORB orb;
    vector<KeyPoint> keyPoints_1, keyPoints_2;
    Mat descriptors_1, descriptors_2;

    orb(img1, Mat(), keyPoints_1, descriptors_1);
    orb(img2, Mat(), keyPoints_2, descriptors_2);
    BruteForceMatcher<HammingLUT> matcher;
    vector<DMatch> matches;

    if (!descriptors_1.data) return 0;
    if (!descriptors_2.data) return 0;

    matcher.match(descriptors_1, descriptors_2, matches);

    double max_dist = 0;
    double min_dist = 70;

    //-- Quick calculation of max and min distances between keypoints
    for( int i = 0; i < descriptors_1.rows; i++ )
    {
        double dist = matches[i].distance;
        if( dist < min_dist ) min_dist = dist;
        if( dist > max_dist ) max_dist = dist;
    }

    //matching orb threshold:0.45*max_dist
    std::vector< DMatch > good_matches;
    for( int i = 0; i < descriptors_1.rows; i++ )
    {
        if( matches[i].distance < 0.6*max_dist )
        {
            good_matches.push_back( matches[i]);
            n++;
        }
    }
    cout << n << endl;

    //Mat result;
    drawMatches(img1, keyPoints_1, img2, keyPoints_2,
        good_matches, result, Scalar::all(-1), Scalar::all(-1),
        vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
    //imshow("match",result);
    //waitKey(0);
    return n;
}


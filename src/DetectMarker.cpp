#include "objectR/setting.h"
#include "objectR/DetectMarker.h"

namespace objectR 
{	
	double tic()
	{
		struct timeval t;
		gettimeofday(&t, nullptr);
		return ((double)t.tv_sec + ((double)t.tv_usec) / 1000000);
	}
	
	/**
	* Normalize angle to be within the interval [-pi,pi].
	*/
	inline double standardRad(double t)
 	{
		if (t >= 0.)
		{
			t = fmod(t+PI, 2*PI) - PI;
		} else 
		{
			t = fmod(t-PI, -2*PI) + PI;
		}
		return t;
	}
	
	void wRo_to_euler(const Eigen::Matrix3d &wRo, double &yaw, double &pitch, double &roll)
	{
		yaw =standardRad(atan2(wRo(1,0), wRo(0,0)));
		double c = cos(yaw);
		double s = sin(yaw);
		pitch = standardRad(atan2(-wRo(2,0), wRo(0,0)*c + wRo(1,0)*s));
		roll  = standardRad(atan2(wRo(0,2)*s - wRo(1,2)*c, -wRo(0,1)*s + wRo(1,1)*c));
	}
	
	// DetectMarker 的定义 ********************
	
	void DetectMarker::findObject()
	{
		Marker marker;
		marker.initialization(this->img_);
		marker.processImage(this->img_, 
							this->markerCenters_, 
							this->translations_, 
							this->eulers_);
	}
	
	void DetectMarker::printResult() // 输出结果
	{
		int l = this->markerCenters_.size(); 
		if (l==0) 
			this->f_ = false;
		cout << "If Find object = " << f_ << endl;
		if (l >1)
		{
			for (int i=0; i<l; i++)
			{
				cout << "distance=" << this->translations_[i].norm()
					<< "m, x=" << this->translations_[i](0)
					<< ", y=" << this->translations_[i](1)
					<< ", z=" << this->translations_[i](2)
					<< ", yaw=" << this->eulers_[i][0]
					<< ", pitch=" << this->eulers_[i][1]
					<< ", roll=" << this->eulers_[i][2]
					<< endl;
			}
			this->f_ = true;
		}	
	}
	
	// Marker 的定义 ****************************
	
	Marker::Marker():
				 tagDetector_(nullptr),
				 tagCodes_(AprilTags::tagCodes16h5),
				 timing(true),
				 tagSize_(setting_tagSize),
				 fx_(setting_fx),
				 fy_(setting_fy),
				 cx_(setting_cx),
				 cy_(setting_cy)
				 {}		 
	
	void Marker::initialization(const Mat img)
	{
		this->width_ = img.cols;
		this->height_ = img.rows;
		this->tagDetector_ = new AprilTags::TagDetector( this->tagCodes_ );
	}
	
	void Marker::processImage(Mat &img, 
							vector<Point2f> &markerCenter, 
							vector<Eigen::Vector3d> &translations, 
							vector<vector<double>> &eulers)
	{
		// RGB图转成灰度图
		Mat img_gray;
		cvtColor(img, img_gray, CV_BGR2GRAY);
		
		double t0;
		if (this->timing)
			t0 = tic();
		
		// 提取Apriltags, 返回detection
		vector<AprilTags::TagDetection> detections = this->tagDetector_->extractTags(img_gray);
		if (this->timing)
		{
			double dt = tic() - t0;
			cout << "Extracting tags took " << dt << " seconds." << endl;
		}
		
		for (int i=0; i<detections.size(); i++)
		{
			// 绘制Apriltags
			detections[i].draw(img);
			
			// 存储每个Apriltags的中心
			Point2f center(detections[i].cxy.first, detections[i].cxy.second);
			markerCenter.push_back(center);
			
			// 计算并存储每个Apriltags计算出的相机位姿
			Eigen::Vector3d translation;
			Eigen::Matrix3d rotation;
			detections[i].getRelativeTranslationRotation(this->tagSize_, this->fx_, this->fy_, this->cx_, this->cy_,
														translation, rotation);
			translations.push_back(translation);
			
			// 从旋转矩阵转换成旋转向量(李群转换成李代数),便于查看
			Eigen::Matrix3d F;
			F <<
				1, 0, 0,
				0, -1, 0,
				0, 0, 1;
			Eigen::Matrix3d fixed_rot = F*rotation;
			double yaw, pitch, roll;
			wRo_to_euler(fixed_rot, yaw, pitch, roll);
			vector<double> e;
			e.push_back(yaw);
			e.push_back(pitch);
			e.push_back(roll);
			eulers.push_back(e);		
		}		
	}
}



























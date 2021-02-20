///////////////////////////////////////////////////////////////////////////
 // Include opencv2
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/fast_math.hpp>

#include <opencv2/imgproc/types_c.h>

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
  // Include CvBridge, Image Transport, Image msg
  // #include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <geometry_msgs/Point.h>

#include<iostream>

using namespace std;
using namespace cv;
std::vector<cv::Point> findBiggestContour(cv::Mat bimg);




static const std::string OPENCV_WINDOW_1 = "Image window 1";

ros::Publisher Gpos_pub;


/**
 * Subscriber callback
 */

void openmvimg(const sensor_msgs::Image::ConstPtr& msg) {

//Set Threshold
cv::Scalar Lower = cv::Scalar (35,43,46);
cv::Scalar Upper = cv::Scalar(77,255,255);

// Convert ROS image to OpenCV image
    cv_bridge::CvImageConstPtr cv_img;

    try
    {
        cv_img = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
        catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    } // Process cv_ptr->image using OpenCV


// Store image in a Mat object 
    cv::Mat cvImg = cv_img->image;
    
       
//blur
    cv::Mat cvImgGBlur;
    cv::GaussianBlur(cvImg, cvImgGBlur, cv::Size(5,5), 3);
  
//convert to HSV
    cv::Mat cvImgHSV;
    cv::cvtColor(cvImgGBlur, cvImgHSV, cv::COLOR_BGR2HSV);

// add mask
    cv::Mat cvMask;
    cv::inRange(cvImgHSV,Lower,Upper,cvMask);

//Erode and Dialate
//Set Core(Element)
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10,10));
    cv::Mat element2 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15,15));
    cv::Mat cvImgErode;
    cv::Mat cvImgDilate;

    cv::erode(cvMask,cvImgErode,element);
    cv::dilate(cvImgErode, cvImgDilate , element);

/*
//Show MAX contour
    Mat cvImgCnt=Mat::zeros(cvImgDilate.size(),CV_8UC1);  
    std::vector< std::vector< cv::Point> > contours;
	std::vector< cv::Point>  biggest_contour;
	std::vector< std::vector< cv::Point> > temp_contours;

	biggest_contour = findBiggestContour(cvImgDilate);
	temp_contours.push_back(biggest_contour);

    drawContours(cvImgCnt, temp_contours,0,Scalar(255),3 );
*/

//**********************Min Enclosing circle**************
    Mat cvcnt = Mat::zeros(cvImgDilate.size(),CV_8UC1);
    Point2f center; 
    float radius;
	minEnclosingCircle(findBiggestContour(cvImgDilate),center,radius);
    circle(cvcnt,center,radius,Scalar(255),3);


//Ouput
//ROS_INFO_STREAM("Center x,y=" << center);

//********************Publish Center Point*************** 
    
    geometry_msgs::Point gpos;
	gpos.x = center.x;
    gpos.y = center.y;
    Gpos_pub.publish(gpos);


//********************imshow*****************************
    //imshow(OPENCV_WINDOW_1 ,cvImgCnt);
    imshow("w2",cvcnt);
    //imshow("w3",cvImgDilate);
    cv::waitKey(3); 
//*******************************************************
}

//*********************Find Biggest COntour*************************************************************
std::vector<cv::Point> findBiggestContour(cv::Mat bimg)
{
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
 
	int largest_area = 0;
	int largest_contour_index = 0;
 
	cv::findContours(bimg, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
 
	for (int i = 0; i < contours.size(); i++) // iterate through each contour. 
	{
		double a = contourArea(contours[i], false);  //  Find the area of contour
		if (a > largest_area){
			largest_area = a;
			largest_contour_index = i;                //Store the index of largest contour
		}
	}
    //ROS_INFO_STREAM("Index" << largest_contour_index);
 
	return contours[largest_contour_index];
    
}
//*****************************************************************************************************




/*
 * Node main function
 */
int main(int argc, char** argv) {
    
     
    ros::init(argc, argv, "openmv");

  
    ros::NodeHandle n;

   
    ros::Subscriber openmv_raw  = n.subscribe("/openmv_cam/image_raw", 10,
                                        openmvimg);


    Gpos_pub = n.advertise<geometry_msgs::Point>("/M1/openmv/Gpos", 100);
     
    ros::spin();

    return 0;
}

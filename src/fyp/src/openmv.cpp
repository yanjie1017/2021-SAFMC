#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/fast_math.hpp>
#include <opencv2/imgproc/types_c.h>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <geometry_msgs/Point.h>
#include<iostream>

using namespace std;
using namespace cv;

std::vector<int> find3BiggestContour(std::vector<std::vector<cv::Point>> contours);

ros::Publisher Gpos_max;


void openmvimg(const sensor_msgs::Image::ConstPtr& msg) {


    //Set Threshold
    cv::Scalar Lower = cv::Scalar (57,198,36);
    cv::Scalar Upper = cv::Scalar(78,255,213);
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
    

    //*****************Find Biggest Contour************************************

    std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
    cv::findContours(cvImgDilate, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    //** Check if contours = 0************

    if(contours.size() != 0 ){

        //**********************Min Enclosing circle**************
        std::vector<int> index_list = find3BiggestContour(contours);

        Mat cvcnt1 = Mat::zeros(cvImgDilate.size(),CV_8UC1);
        Point2f center1; 
        float radius1;
	    minEnclosingCircle(contours[index_list[0]],center1,radius1);
        circle(cvcnt1,center1,radius1,Scalar(255),1);
        //ROS_INFO_STREAM("Index_1 " << index_list[0]);
            //********************Publish Center of Each Blob*************** 
    
        geometry_msgs::Point gpos_max;
	    gpos_max.x = center1.x;
        gpos_max.y = center1.y;
        Gpos_max.publish(gpos_max);
    
        //********************imshow*****************************
        imshow("Target",cvcnt1);
        //imshow("BW",cvImgDilate);    
    }
    imshow("RAW",cvImg);
    //imshow("Mask",cvMask);
    //imshow("Erode",cvImgErode);
    //imshow("Dilate",cvImgDilate);
    cv::waitKey(3);  

}


std::vector<int> find3BiggestContour(std::vector<std::vector<cv::Point>> contours)
{   
    std::vector<int> index_list;
	int largest_area_3rd = 0;
    int largest2_area_3rd =0;
    int largest3_area =0;
	int largest3_contour_index =0;
    int largest_contour_index =0;
    int largest2_contour_index =0;
    int largest4_area =0;
    int largest4_contour_index =0;
 
	for (int i = 0; i < contours.size(); i++) // iterate through each contour. 
	{
		double a3 = contourArea(contours[i], false);  //  Find the area of contour
		if (a3 > largest_area_3rd){
			largest_area_3rd = a3;
			largest_contour_index = i;                //Store the index of largest contour
		}
        //ROS_INFO_STREAM("Index1 " << largest_contour_index);

	}
    
    //ROS_INFO_STREAM("Index4 " << largest4_contour_index);

    index_list.push_back(largest_contour_index);
    ROS_INFO_STREAM("Index_1 " << index_list[0]);
	return index_list;
    
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


    Gpos_max = n.advertise<geometry_msgs::Point>("/M1/openmv/Gpos_max", 100);

     
     
    ros::spin();

    return 0;
}

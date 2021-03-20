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

std::vector<int> find3BiggestContour(std::vector<std::vector<cv::Point>> contours);

ros::Publisher Gpos_max;
ros::Publisher Gpos_2nd;
ros::Publisher Gpos_3rd;
ros::Publisher Gpos_4th;
ros::Publisher Gpos_center;



void openmvimg(const sensor_msgs::Image::ConstPtr& msg) {

    //Set Threshold
    //cv::Scalar Lower = cv::Scalar (72,150,148);
    //cv::Scalar Upper = cv::Scalar(87,255,220);
    //Indoorr Test
    cv::Scalar Lower = cv::Scalar (35,43,46);
    cv::Scalar Upper = cv::Scalar(77,255,255);
    //cv::Scalar Lower = cv::Scalar (65,1416,71);
    //cv::Scalar Upper = cv::Scalar (82,224,153);

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
        // Show size
    cv::Size s = cvImg.size();
    int rows = cvImg.rows;
    int cols = cvImg.cols;
    rows = s.height;
    cols = s.width;
    ROS_INFO("Size: %i x %i", cols, rows);

       
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
        circle(cvcnt1,center1,radius1,Scalar(255),3);
        //ROS_INFO_STREAM("Index_1 " << index_list[0]);

        Point2f center2; 
        float radius2;
	    minEnclosingCircle(contours[index_list[1]],center2,radius2);
	    circle(cvcnt1,center2,radius2,Scalar(255),3);
        //ROS_INFO_STREAM("Index_2 " << index_list[1]);

        Point2f center3; 
        float radius3; 
	    minEnclosingCircle(contours[index_list[2]],center3,radius3);
        circle(cvcnt1,center3,radius3,Scalar(255),3);
        //ROS_INFO_STREAM("Index_3 " << index_list[2]);

        Point2f center4; 
        float radius4; 
	    minEnclosingCircle(contours[index_list[3]],center4,radius4);
        circle(cvcnt1,center4,radius4,Scalar(255),3);

        if(index_list[0] != index_list[1] != index_list[2] != index_list[3]){
            //***********************Publish Center of 4 color blobs****************************
            geometry_msgs::Point gpos_center;
	        gpos_center.x = (center1.x + center2.x + center3.x + center4.x) / 4;
            gpos_center.y = (center1.y + center2.y + center3.y + center4.y) / 4;
            Gpos_center.publish(gpos_center);
        }
        else{
            //********************Publish Center of Each Blob*************** 
    
            geometry_msgs::Point gpos_max;
	        gpos_max.x = center1.x;
            gpos_max.y = center1.y;
            Gpos_max.publish(gpos_max);

            geometry_msgs::Point gpos_2nd;
	        gpos_2nd.x = center2.x;
            gpos_2nd.y = center2.y;
            Gpos_2nd.publish(gpos_2nd);

            geometry_msgs::Point gpos_3rd;
	        gpos_3rd.x = center3.x;
            gpos_3rd.y = center3.y;
            Gpos_3rd.publish(gpos_3rd);
    
            geometry_msgs::Point gpos_4th;
	        gpos_3rd.x = center4.x;
            gpos_3rd.y = center4.y;
            Gpos_3rd.publish(gpos_4th);
        }     
        //********************imshow*****************************
 
        imshow("Target",cvcnt1);
        imshow("BW",cvImgDilate);
    
    
    }
    imshow("RAW",cvImg);
    cv::waitKey(3);  

}

//*****************************Find 3rd Biggestlargest2_contour_index = j; 
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
    for (int j = 0; j < contours.size(); j++){ // iterate through each contour. 
		double a3 = contourArea(contours[j], false);  //  Find the area of contour
		if (a3 < largest_area_3rd && a3 > largest2_area_3rd){
			largest2_area_3rd = a3;
            largest2_contour_index = j;

		}
    }
    //ROS_INFO_STREAM("Index2 " << largest2_contour_index);

    for (int k = 0; k < contours.size(); k++) {
		double a3 = contourArea(contours[k], false);  //  Find the area of contour
		if (a3 < largest2_area_3rd && a3 > largest3_area){
			largest3_area = a3;
            largest3_contour_index = k; 
    	}

    }
    //ROS_INFO_STREAM("Index3 " << largest3_contour_index);

    for (int l = 0; l < contours.size(); l++) {
		double a3 = contourArea(contours[l], false);  //  Find the area of contour
		if (a3 < largest3_area && a3 > largest4_area){
			largest4_area = a3;
            largest4_contour_index = l; 
    	}

    }
    //ROS_INFO_STREAM("Index4 " << largest4_contour_index);

    index_list.push_back(largest_contour_index);
    index_list.push_back(largest2_contour_index);
    index_list.push_back(largest3_contour_index);
    index_list.push_back(largest4_contour_index);

    ROS_INFO_STREAM("Index_1 " << index_list[0]);
    ROS_INFO_STREAM("Index_2 " << index_list[1]);
    ROS_INFO_STREAM("Index_3 " << index_list[2]);
    ROS_INFO_STREAM("Index_3 " << index_list[3]);
 
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
    Gpos_2nd = n.advertise<geometry_msgs::Point>("/M1/openmv/Gpos_2nd", 100);
    Gpos_3rd = n.advertise<geometry_msgs::Point>("/M1/openmv/Gpos_3rd", 100);
    Gpos_4th = n.advertise<geometry_msgs::Point>("/M1/openmv/Gpos_4th", 100);
    Gpos_center = n.advertise<geometry_msgs::Point>("/M1/openmv/Gpos_center", 100);
     
     
    ros::spin();

    return 0;
}

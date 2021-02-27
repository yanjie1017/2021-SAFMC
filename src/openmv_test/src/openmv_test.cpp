#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/types.hpp>

#include <opencv2/imgproc/types_c.h>

#include <ros/ros.h>
#include <sensor_msgs/Image.h>

#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include <std_msgs/Bool.h>
#include <iostream>


int count = 0;
std::string imgCount;
const std::string path = "/home/safmc/Openmv_ImgSaved/";

cv::Mat cvImg;

void SaveImg(cv::Mat Img){
    count = count + 1;
    imgCount = std::to_string(count);
    std::string imgName = path + "Img" + imgCount + ".png";
    cv::imwrite(imgName, Img);
    // Publish message
    ROS_INFO("Image saved.");
}


void test(const std_msgs::Bool::ConstPtr& msg) {
    if (msg->data){
        SaveImg(cvImg);
    }
}

void openmvimg(const sensor_msgs::Image::ConstPtr& msg) {

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

    cvImg = cv_img->image;

    cv::imshow("Image", cvImg);

    cv::waitKey(3);  

}


/*
 * Node main function
 */
int main(int argc, char** argv) {
    
     
    ros::init(argc, argv, "openmv_test");

  
    ros::NodeHandle n;

   
    ros::Subscriber openmv_raw  = n.subscribe("/openmv_cam/image_raw", 10,
                                        openmvimg);

    ros::Subscriber capture  = n.subscribe("/openmv_cam/test", 10,
                                        test);

    ros::spin();

    return 0;
}

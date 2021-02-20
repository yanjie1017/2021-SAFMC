///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2018, STEREOLABS.
//
// All rights reserved.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////

/**
 * This tutorial demonstrates how to receive the Left and Right rectified images
 * from the ZED node
 */


  // Include the ROS library
#include <ros/ros.h>
#include <geometry_msgs/Point.h>

  // Include opencv2
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/fast_math.hpp>

  // Include CvBridge, Image Transport, Image msg
  // #include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

/**
 * Subscriber callbacks. The argument of the callback is a constant pointer to the received message
 */

static const std::string OPENCV_WINDOW_1 = "Image window 1";
static const std::string OPENCV_WINDOW_2 = "Image window 2";

ros::Publisher WindowCtr_pub;

void Window_LeftRectGray_Callback(const sensor_msgs::Image::ConstPtr& msg) {
    
    // Convert ROS image to OpenCV image
    cv_bridge::CvImageConstPtr cv_ptr;
    try
    {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);
    }
        catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    } // Process cv_ptr->image using OpenCV

    // Store image in a Mat object 
    cv::Mat cvImgGry = cv_ptr->image;
    // Size: 1280x720
    
    // Resize
    cv::Mat cvImgResized;
    cv::resize(cvImgGry, cvImgResized, cv::Size(), 0.5, 0.5);
    // Size: 640x360

    /*
    // Show number of channels
    int channel = cvImgGry.channels();
    ROS_INFO("Channels: %i", channel);   
    // Show size
    cv::Size s = cvImgGry.size();
    int rows = cvImgGry.rows;
    int cols = cvImgGry.cols;
    rows = s.height;
    cols = s.width;
    ROS_INFO("Size: %i x %i", cols, rows);
    */

    // Gaussian blur
    cv::Mat cvImgGBlur;
    cv::GaussianBlur(cvImgResized, cvImgGBlur, cv::Size(5,5), 3); 

    /*
    // Median blur
    cv::Mat cvImgMBlur;
    cv::medianBlur(cvImgGry, cvImgMBlur, 5);
    // Bilateral blur
    cv::Mat cvImgBBlur;
    cv::bilateralFilter(cvImgGry, cvImgBBlur, 5, 75, 75);
    */

    // Canny edge detection
    cv::Mat cvImgGCny;
    cv::Canny(cvImgGBlur, cvImgGCny, 100, 200); //cvImgCanny: CV_8U
    
    /*
    //Thresholding - Threhold binary
    cv::Mat cvImgThres;
    cv::threshold(cvImgGCny, cvImgThres, 128, 255, 0);
    
    // Morphology closing
    cv::Mat kernel = cv::Mat::ones(3,3,CV_8U);
    cv::Mat cvImgClose;
    cv::morphologyEx(cvImgGCny, cvImgClose, 3, kernel);
    */

    // Erode + Dilate
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5,5));
    cv::Mat cvImgErode;
    cv::Mat cvImgDilate;
    cv::dilate(cvImgGCny,cvImgDilate,element);
    cv::erode(cvImgDilate, cvImgErode , element);
    

    // Hough Gradient
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(cvImgErode, circles, 3, 2, cvImgGCny.rows, 200, 100 , 5, cvImgGCny.cols/2.5); 
    // HoughCircles(image, method, dp, minDist[, circles[, param1[, param2[, minRadius[, maxRadius]]]]])

    // Draw circles
    cv::Mat cvImgCtr = cvImgResized.clone();
    
    for(std::size_t i = 0; i < circles.size(); i++ )
    { 
      // circles = (x,y,radius)
      cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // draw the circle center
      //cv::circle(cvImgCtr, center, 3, cv::Scalar(0,255,0), -1);
      // draw the circle outline
      cv::circle(cvImgCtr, center, radius, cv::Scalar(0,0,255), 3);
      
      // Publish centre point (640 x 360)
      geometry_msgs::Point windowCtr;
	    windowCtr.x = circles[i][0];
	    windowCtr.y = circles[i][1];
	    windowCtr.z = 0;
      WindowCtr_pub.publish(windowCtr);

    }

    cv::imshow("Window", cvImgDilate);
    cv::imshow(OPENCV_WINDOW_1, cvImgErode);
    cv::imshow(OPENCV_WINDOW_2, cvImgCtr);

    cv::waitKey(3); 

}

/*
void depthLeftCallback(const sensor_msgs::Image::ConstPtr& msg) {
  ROS_INFO("Left depth image received from ZED - Size: %dx%d", msg->width, msg->height);
}
*/


int main(int argc, char** argv) {

    ros::init(argc, argv, "zed_window_subscriber");

    ros::NodeHandle n;
 
    ros::Subscriber Window_LeftRectGray  = n.subscribe("/zedm/zed_node/left/image_rect_gray", 10,
                                        Window_LeftRectGray_Callback);

    /*
    ros::Subscriber subLeftDepth  = n.subscribe("/zedm/zed_node/depth/depth_registered", 10,
                                        depthLeftCallback);
    */
                                  
    WindowCtr_pub = n.advertise<geometry_msgs::Point>("M3/zed/WindowCtr", 100);

    ros::spin();

    return 0;
}


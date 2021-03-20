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

void LeftRect_Callback(const sensor_msgs::Image::ConstPtr& msg) {
    
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

    cv::imshow("Left", cvImgResized);

    cv::waitKey(3); 


}

void RightRect_Callback(const sensor_msgs::Image::ConstPtr& msg) {
    
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

    cv::imshow("Right", cvImgResized);

    cv::waitKey(3); 


}


int main(int argc, char** argv) {

    ros::init(argc, argv, "zed_stereo");

    ros::NodeHandle n;
 
    ros::Subscriber LeftRect  = n.subscribe("/zedm/zed_node/left/image_rect_color", 10,
                                        LeftRect_Callback);
    ros::Subscriber RightRect  = n.subscribe("/zedm/zed_node/right/image_rect_color", 10,
                                        RightRect_Callback);


    ros::spin();

    return 0;
}


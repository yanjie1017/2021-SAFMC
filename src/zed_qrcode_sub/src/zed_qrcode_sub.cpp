// Include the ROS library
#include <ros/ros.h>

// Include opencv2
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>


// Include CvBridge, Image Transport, Image msg
// #include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

// Include Zbar
#include <zbar.h>
using namespace zbar;

// Image saving name/location
int count = 0;
std::string imgCount;
const std::string path = "/home/safmc/QRCode_ImgSaved/";

// QR Code decoded info
std::string decoded;

// Crop image
int row = 4;
int col = 4;


typedef struct{
  std::string type;
  std::string data;
  std::vector <cv::Point> location;
} decodedObject;


void SaveImg(cv::Mat Img){
    count += 1;
    imgCount = std::to_string(count);
    std::string imgName = path + "QRcodeImg" + imgCount + ".png";
    cv::imwrite(imgName, Img);
    // Publish message
    ROS_INFO("QR Code detected. Image saved.");
}

void ScanImg(cv::Mat Img, cv::Mat cvImg){
    // ZBar scanner
    zbar::ImageScanner scanner;
    scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE , 1); // scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE, 1);
    zbar::Image zbarImg(Img.cols, Img.rows, "Y800", (uchar *)Img.data, Img.cols * Img.rows);
    // zbar::Image zbarImg(cvImgResized.cols, cvImgResized.rows, "Y800", (uchar *)cvImgResized.data, cvImgResized.cols * cvImgResized.rows);
    
    int n = scanner.scan(zbarImg);

    for(zbar::Image::SymbolIterator symbol = zbarImg.symbol_begin(); symbol != zbarImg.symbol_end(); ++symbol)
    {   
        // Print decoded info
        decodedObject obj;
        obj.data = symbol->get_data();
        ROS_INFO_STREAM("Data : " << obj.data );

        // Save image if current decoded != last decoded
        if (obj.data!=decoded){
            SaveImg(cvImg);
        }

        decoded = obj.data;
    }
}

void QRCode_LeftRectGray_Callback(const sensor_msgs::Image::ConstPtr& msg) {

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
    // 1280x720
 
    // Crop image
    int numOfRows = std::floor(720/row);
    int numOfCols = std::floor(1280/col);

    for(int i = 0; i < row; i++ ){
        for (int j = 0; j < col; j++ ){
            cv::Mat cvImgCrop;
            cvImgGry(cv::Rect(numOfCols*j,numOfRows*i,numOfCols,numOfRows)).copyTo(cvImgCrop);
            ScanImg(cvImgCrop, cvImgGry);
                //cv::imshow("raw", cvImgCrop);
                //cv::waitKey(3); 
        }
    }

    cv::imshow("raw", cvImgGry);
    cv::waitKey(3); 

}



int main(int argc, char** argv) {

    ros::init(argc, argv, "zed_QRcode");

    ros::NodeHandle n;

    ros::Subscriber QRCode_LeftRectGray  = n.subscribe("/zedm/zed_node/left/image_rect_gray", 10,
                                        QRCode_LeftRectGray_Callback);

    ros::spin();

    return 0;
}


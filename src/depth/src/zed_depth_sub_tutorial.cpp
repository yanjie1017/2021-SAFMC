#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/String.h>

/**
 * Subscriber callback
 */

ros::Publisher Depth_pub;

void depthCallback(const sensor_msgs::Image::ConstPtr& msg) {
    
    float depsum = 0.0;
    float depave = 0.0;
    int i =0;
    int numbers = 0;


    // Get a pointer to the depth values casting the data
    // pointer to floating point
    float* depths = (float*)(&msg->data[0]);

    // Image coordinates of the center pixel
    int u = msg->width / 2;
    int v = msg->height / 2;
    //int z = (msg->width * msg->height )- 1;
    
    //sum of 4 rolls in the middle 
    //640*360, width*height
    //ROS_INFO("width: %d and height: %d", u , v);

    while (i <640){
        if (isnan(depths[i+114560])){
            i ++;
            continue;
        }
        else{
            depsum += depths[i+114560];
            numbers +=1;
        }
        
        i ++ ;
    }
    depave = depsum / numbers;

    // Linear index of the center pixel
    int centerIdx = u + msg->width * v;

    // Output the measure
    ROS_INFO("Center distance : %g m", depths[centerIdx]);
    ROS_INFO("Average distance : %f m", depave);
    ROS_INFO("Sum distance : %f m", depsum);
    //ROS_INFO("Center distance : %g m", depths[z]);

    std_msgs::String depth;

    if ((abs(depths[centerIdx] - depave))>0.2){
        depth.data = "M2YES";
    } else{
        depth.data = "M2NO";
    }

    Depth_pub.publish(depth);

}

/**
 * Node main function
 */
int main(int argc, char** argv) {

    ros::init(argc, argv, "zed_video_subscriber");

    ros::NodeHandle n;

    ros::Subscriber subDepth = n.subscribe("/zedm/zed_node/depth/depth_registered", 10, depthCallback);

    Depth_pub = n.advertise<std_msgs::String>("/M2/zed/depth", 100);

    ros::spin();

    return 0;
}

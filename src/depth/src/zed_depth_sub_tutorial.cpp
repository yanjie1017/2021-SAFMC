#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>

/**
 * Subscriber callback
 */

ros::Publisher Depth_ind_pub;
ros::Publisher Depth_val_pub;

void depthCallback(const sensor_msgs::Image::ConstPtr& msg) {
    
    float depsum = 0.0;
    float depave = 0.0;
    float cdepth = 0.0;
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

    cdepth = depths[centerIdx];

    std_msgs::String depth_ind;
    std_msgs::Float32 depth_val;

    if ((abs(depths[centerIdx] - depave))>0.2){
        depth_ind.data = "M2YES";
    } else{
        depth_ind.data = "M2NO";
    }

    if(isnan(depths[centerIdx])){
        depth_val.data = 0;
    }else{
        depth_val.data = cdepth; 
    }

    Depth_ind_pub.publish(depth_ind);
    Depth_val_pub.publish(depth_val);


}

/**
 * Node main function
 */
int main(int argc, char** argv) {

    ros::init(argc, argv, "zed_video_subscriber");

    ros::NodeHandle n;

    ros::Subscriber subDepth = n.subscribe("/zedm/zed_node/depth/depth_registered", 10, depthCallback);

    Depth_ind_pub = n.advertise<std_msgs::String>("/M2/zed/depth_ind", 100);
    Depth_val_pub = n.advertise<std_msgs::Float32>("/M2/zed/depth_val", 100);

    ros::spin();

    return 0;
}

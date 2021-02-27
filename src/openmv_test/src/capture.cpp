
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <iostream>

ros::Publisher capture_pub;

int main(int argc, char** argv) {
    
    ros::init(argc, argv, "capture");

    ros::NodeHandle n;

    capture_pub = n.advertise<std_msgs::Bool> ("/openmv_cam/test", 10);

    while(true){
        int x;
        std::cout << "Enter value: ";
        std::cin >> x;
        //cout << "Your value is: " << x;
        if (x == 1){
            std_msgs::Bool command;
            command.data = true;
            capture_pub.publish(command);
        }
    }

    ros::spin();

    return 0;
}
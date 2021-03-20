#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>

#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Matrix3x3.h"
#include "tf2/LinearMath/Vector3.h"
#include "tf2/LinearMath/Scalar.h"
#include "tf2/LinearMath/Transform.h"

#include <string>

#define RAD2DEG 57.295779513

ros::Publisher pose_pub;


// change of coordinates from NWU to ENU
//tf2::tf2Scalar roll_cam = 0, pitc = 0, yaw = 1.5707963, gamma_world = -1.5707963;

tf2::Matrix3x3 NWUtoENU(0,-1,0,
                        1,0,0,
                        0,0,1); 

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg) {

    // Camera position in map frame
    double tx = msg->pose.pose.position.x;
    double ty = msg->pose.pose.position.y;
    double tz = msg->pose.pose.position.z;

    // Orientation quaternion
    tf2::Quaternion q(
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z,
        msg->pose.pose.orientation.w);

    // 3x3 Rotation matrix from quaternion
    tf2::Matrix3x3 m(q);

    // Roll Pitch and Yaw from rotation matrix
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    // Output the measure
    ROS_INFO("Received odom in '%s' frame : X: %.2f Y: %.2f Z: %.2f - R: %.2f P: %.2f Y: %.2f",
             msg->header.frame_id.c_str(),
             tx, ty, tz,
             roll * RAD2DEG, pitch * RAD2DEG, yaw * RAD2DEG);    
}


void poseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg) {

    // Camera position in map frame
    double tx = msg->pose.position.x;
    double ty = msg->pose.position.y;
    double tz = msg->pose.position.z;

    // Vector
    tf2::Vector3 v(
        msg->pose.position.x,
        msg->pose.position.y,
        msg->pose.position.z);

    // Orientation quaternion
    tf2::Quaternion q(
        msg->pose.orientation.x,
        msg->pose.orientation.y,
        msg->pose.orientation.z,
        msg->pose.orientation.w);

    // 3x3 Rotation matrix from quaternion
    tf2::Matrix3x3 m(q);

    // Roll Pitch and Yaw from rotation matrix
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    // Output the measure
    ROS_INFO("Received pose in '%s' frame : X: %.2f Y: %.2f Z: %.2f - R: %.2f P: %.2f Y: %.2f",
             msg->header.frame_id.c_str(),
             tx, ty, tz,
             roll * RAD2DEG, pitch * RAD2DEG, yaw * RAD2DEG);

    // for ROS (ENU) ************************************************************
    tf2::Vector3 vpose_ENU;
    tf2::Quaternion qpose_ENU;

    vpose_ENU = NWUtoENU * v;

    qpose_ENU.setRPY(roll, -pitch, yaw);
    tf2::Matrix3x3 n(qpose_ENU);
    double roll_ENU, pitch_ENU, yaw_ENU;
    n.getRPY(roll_ENU, pitch_ENU, yaw_ENU);
    /*
    qo_f1 = orientation of frame F1 as seen from frame F2
    qo_f2  = orientation of frame F2 is as seen from F1
    q_f1 = some quaternion in F1 frame
    q_f2 = q_f1 as seen from F2 

    q_f2 = qo_f2 * q_f1 * qo_f2.inverse()
    */

    ROS_INFO_STREAM("ENU: x: " << vpose_ENU.getX() << " y:" << vpose_ENU.getY() << " z:" << vpose_ENU.getZ()
                    << " | r: " << roll_ENU * RAD2DEG << " p: " << pitch_ENU * RAD2DEG << " y: " << yaw_ENU * RAD2DEG);
    
    // Publish messages
    geometry_msgs::PoseStamped pose_ENU;
    pose_ENU.header = msg->header;
    pose_ENU.pose.position.x = vpose_ENU.getX();
    pose_ENU.pose.position.y = vpose_ENU.getY();
    pose_ENU.pose.position.z = vpose_ENU.getZ();
    pose_ENU.pose.orientation.x = qpose_ENU.getX();
    pose_ENU.pose.orientation.y = qpose_ENU.getY();
    pose_ENU.pose.orientation.z = qpose_ENU.getZ();
    pose_ENU.pose.orientation.w = qpose_ENU.getW();

    pose_pub.publish(pose_ENU);     
}

void posewithcovCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) {

    // Camera position in map frame
    double tx = msg->pose.pose.position.x;
    double ty = msg->pose.pose.position.y;
    double tz = msg->pose.pose.position.z;

    // Orientation quaternion
    tf2::Quaternion q(
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z,
        msg->pose.pose.orientation.w);

    // 3x3 Rotation matrix from quaternion
    tf2::Matrix3x3 m(q);

    // Roll Pitch and Yaw from rotation matrix
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    
    // Output the measure
    ROS_INFO("Received pose in '%s' frame : X: %.2f Y: %.2f Z: %.2f - R: %.2f P: %.2f Y: %.2f",
             msg->header.frame_id.c_str(),
             tx, ty, tz,
             roll * RAD2DEG, pitch * RAD2DEG, yaw * RAD2DEG);
}


/**
 * Node main function
 */
int main(int argc, char** argv) {

    ros::init(argc, argv, "vio");

    ros::NodeHandle n;

    //ros::Subscriber subOdom    = n.subscribe("/zedm/zed_node/odom", 10, odomCallback);
    ros::Subscriber subPose    = n.subscribe("/zedm/zed_node/pose", 10, poseCallback);
    //ros::Subscriber subPoseWithCov = n.subscribe("/zedm/zed_node/pose_with_covariance", 10, posewithcovCallback);
    
    pose_pub = n.advertise<geometry_msgs::PoseStamped>("/zedm/vision_pose", 10);
    
    ros::spin();

    return 0;
}


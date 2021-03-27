/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped init_pose;
    init_pose.pose.position.x = 0;
    init_pose.pose.position.y = 0;
    init_pose.pose.position.z = 0.5;
     geometry_msgs::PoseStamped pose;
    //send a few setpoints before starting
    for(int i = 50; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();
    ros::Time armed_time = ros::Time::now();
    ros::Duration mission_time;
    bool armed = false;
    bool offb_entered = false;
    double mission_step = 5;
    double dist = 2;
    double vel = dist/mission_step;

    while(ros::ok()&& !armed){
        if( !offb_entered && current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(2.0))){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
                offb_entered = true;
            }
            last_request = ros::Time::now();
        } else {
            if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(2.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                    armed_time = ros::Time::now();
                    armed = true;
                }
                last_request = ros::Time::now();
            }
        }
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }
    while(ros::ok() && armed){
        if (!armed){
            pose = init_pose;
        }
        
        else {
            mission_time = ros::Time::now() - armed_time;
            double secs = mission_time.toSec();
            if (secs < 5){
                pose.pose.position.x = 0;
                pose.pose.position.y = 0;
                pose.pose.position.z = 0.3*(secs);
                if (pose.pose.position.z > 1.5){
                    pose.pose.position.z = 1.5;
                }
                
            }/*
            else if(secs < (5+mission_step)){
                double dt = secs - mission_step;
                pose.pose.position.x = 0;
                pose.pose.position.y = -vel*dt; //-2
                pose.pose.position.z = 1.5;
            }
            else if(secs < (5+2*mission_step)){
                double dt = secs - 2*mission_step;
                pose.pose.position.x = vel*dt; //2
                pose.pose.position.y = -dist; //-2
                pose.pose.position.z = 1.5;
            }
            else if(secs < (5+3*mission_step)){
                double dt = secs - 3*mission_step;
                pose.pose.position.x = dist;
                pose.pose.position.y = -dist+vel*dt;
                pose.pose.position.z = 1.5;
            }
            else if(secs<(5+4*mission_step)){
                double dt = secs - 4*mission_step;
                pose.pose.position.x = dist-vel*dt;
                pose.pose.position.y = 0;
                pose.pose.position.z = 1.5;
            }
            else if(secs < (5+5*mission_step)){
                double dt = secs - 5 * mission_step;
                pose.pose.position.x = 0;
                pose.pose.position.y = -vel*dt; //-2
                pose.pose.position.z = 1.5;
            }
            else if(secs < (5+6*mission_step)){
                double dt = secs - 6*mission_step;
                pose.pose.position.x = vel*dt; //2
                pose.pose.position.y = -dist; //-2
                pose.pose.position.z = 1.5;
            }
            else if(secs < (5+7*mission_step)){
                double dt = secs - 7*mission_step;
                pose.pose.position.x = dist;
                pose.pose.position.y = -dist+vel*dt;
                pose.pose.position.z = 1.5;
            }
            else if(secs<(5+8*mission_step)){
                double dt = secs - 8*mission_step;
                pose.pose.position.x = dist-vel*dt;
                pose.pose.position.y = 0;
                pose.pose.position.z = 1.5;
            }
           
            else {
                pose.pose.position.x = 0;
                pose.pose.position.y = 0;
                pose.pose.position.z = 1.5;
            }*/
            
            }
        local_pos_pub.publish(pose);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

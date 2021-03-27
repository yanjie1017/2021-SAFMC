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
#include <math.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/UInt16.h>
#include <mavros_msgs/PositionTarget.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include <mavros_msgs/CommandTOL.h>
#define PI 3.1415926
#define INCREMENT 0.01


mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

geometry_msgs::PoseStamped current_pose;
void uavPoseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
    current_pose = *msg;
}

geometry_msgs::PoseStamped mission1_center;
geometry_msgs::PoseStamped mission2_center;
geometry_msgs::PoseStamped mission2_temp;

geometry_msgs::Point marker_center;
void markerCenterCallback(const geometry_msgs::Point::ConstPtr& msg)
{
    marker_center = *msg;
}

geometry_msgs::Point marker_found;
void markerFoundCallback(const geometry_msgs::Point::ConstPtr& msg)
{
    marker_found = *msg;
}

std_msgs::String depth_ind;
void depthIndCallback(const std_msgs::String::ConstPtr& msg) 
{
    depth_ind = *msg;
}

std_msgs::Float32 depth_val;
void depthValCallback(const std_msgs::Float32::ConstPtr& msg) 
{
    depth_val = *msg;
}

ros::ServiceClient land_client; 
mavros_msgs::CommandTOL land_cmd;

bool findMarker (int flag, geometry_msgs::PoseStamped& pose, ros::Publisher& local_pos_pub) {
    ros::Rate rate(20.0);
    int i = 0;
    if (flag == 1) {//move forward to find the marker
        while (!marker_found.x && ros::ok() && i < (2 / INCREMENT + 1)) {
            pose.pose.position.x += INCREMENT;
            i++;
            std::cout << "FINDING MARKER. MOVED " << i * INCREMENT << " FORWARD IN TOTAL" << std::endl;
            local_pos_pub.publish(pose);
            ros::spinOnce();
            rate.sleep();
    
        }
        pose = current_pose;
        if (i >= (2 / INCREMENT + 1)) {
            ROS_INFO("COULDN'T FIND MARKER");
            return false;
        } else if (marker_found.x && i < (2 / INCREMENT + 1)) {
            return true;
        }
    } else {//move right to find the marker
        while (!marker_found.x && ros::ok() && i < 2 / INCREMENT + 1) {
            pose.pose.position.y -= INCREMENT;
            local_pos_pub.publish(pose);
            ros::spinOnce();
            rate.sleep();
    
        }
    }
}

void adjust(geometry_msgs::PoseStamped& pose, ros::Publisher& local_pos_pub, float THRESHOLD) {
    std::cout << "START ADJUSTING" <<std::endl; 
    bool flag = true;
    
    float x_diff;
    float y_diff;
    float uav_center_x = 320;
    float uav_center_y = 240;
    
    ros::Rate rate(20.0);
    while(flag && ros::ok()) {
        x_diff = marker_center.x - uav_center_x;
        y_diff = marker_center.y - uav_center_y;
        

        if (abs(x_diff) > THRESHOLD) {
            if (x_diff > 0) {
                std::cout << "ADJUSTING: move right" <<std::endl; 
                pose.pose.position.y -= INCREMENT;
            } else {
                std::cout << "ADJUSTING: move left" <<std::endl;
                pose.pose.position.y += INCREMENT;
            }
        }

        if (abs(y_diff) > THRESHOLD) {
            if (y_diff > 0) {
                std::cout << "ADJUSTING: move backward" <<std::endl;
                pose.pose.position.x -= INCREMENT;
            } else {
                std::cout << "ADJUSTING: move forward" <<std::endl;
                pose.pose.position.x += INCREMENT;
            }
        }

        if ((fabs(x_diff) <= THRESHOLD) && (fabs(y_diff) <= THRESHOLD)) {
            std::cout << "ALIGNED WITH MARKER" <<std::endl;
            flag = false;
            pose = current_pose;
        }
        
        local_pos_pub.publish(pose);

        
        std::cout << "MARKER pose: "<< pose.pose.position.x << " " << pose.pose.position.y << " " << pose.pose.position.z;
        std::cout << " current_pose: "<< current_pose.pose.position.x << " " << current_pose.pose.position.y << " " << current_pose.pose.position.z << std::endl;
        
        ros::spinOnce();
        rate.sleep();
    }
}

void hover(geometry_msgs::PoseStamped& pose, ros::Publisher& local_pos_pub) {
    ros::Rate rate(20.0);
    local_pos_pub.publish(pose);
    ros::spinOnce();
    rate.sleep();
}

void move_to(float x, float y, float z, geometry_msgs::PoseStamped& pose, ros::Publisher& local_pos_pub) {
    ros::Rate rate(20.0);
    pose.pose.position.x = x;
    pose.pose.position.y = y;
    pose.pose.position.z = z;
    while (!((fabs(current_pose.pose.position.x - pose.pose.position.x) < 0.05) && (fabs(current_pose.pose.position.y - pose.pose.position.y) < 0.05) && (fabs(current_pose.pose.position.z - pose.pose.position.z) < 0.05))) {
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }
}

/*bool check_green()
 {
     if (is_green) {
     return true;
     }
     return false;
 }*/
void  drop_payload(ros::Publisher& servo_pub, std_msgs::UInt16 servo_num, ros::Publisher& local_pos_pub) {
    ros::Rate rate(20.0);
    ros::Time last_request = ros::Time::now();
    servo_pub.publish(servo_num);
    while (ros::Time::now() - last_request < ros::Duration(8.0)) {
        local_pos_pub.publish(current_pose);
        ros::spinOnce();
        rate.sleep();
    }
 }

void go_and_drop(float x, float y, geometry_msgs::PoseStamped& pose, ros::Publisher& local_pos_pub, std_msgs::UInt16 servo_num, ros::Publisher& servo_pub) {
    move_to(mission1_center.pose.position.x + x, mission1_center.pose.position.y + y, 1.5, pose, local_pos_pub);

        if (1) {//if(is_green())
            move_to(mission1_center.pose.position.x + x, mission1_center.pose.position.y + y, 0.3, pose, local_pos_pub);
            drop_payload(servo_pub, servo_num, local_pos_pub);
        } else {
            move_to(mission1_center.pose.position.x + x, mission1_center.pose.position.y + y, 1.5, pose, local_pos_pub);
        }
        
        move_to(mission1_center.pose.position.x, mission1_center.pose.position.y, 1.5, pose, local_pos_pub);
}

void avoid_crash(int flag, mavros_msgs::PositionTarget& pos_sp, ros::Publisher& position_setpoint_pub) {
    ros::Rate rate(20.0);
    if (depth_val.data < 0.5) {
        switch(flag) {
            case 1: {
                pos_sp.position.x -= INCREMENT;
                break;
            }
            case 2: {
                pos_sp.position.y -= INCREMENT;
                break;
            }
            case 3: {
                pos_sp.position.x += INCREMENT;
                break;
            }
            case 4: {
                pos_sp.position.y += INCREMENT;
                break;
            }
        }
           
    } else if (depth_val.data > 0.7) {
        switch(flag) {
            case 1: {
                pos_sp.position.x += INCREMENT;
                break;
            }
            case 2: {
                pos_sp.position.y += INCREMENT;
                break;
            }
            case 3: {
                pos_sp.position.x -= INCREMENT;
                break;
            }
            case 4: {
                pos_sp.position.y -= INCREMENT;
                break;
            }
        }
        
    }
    position_setpoint_pub.publish(pos_sp);
    ros::spinOnce();
    rate.sleep();
}


void match_with_curr(mavros_msgs::PositionTarget& pos_sp) {
    pos_sp.position.x = current_pose.pose.position.x;
    pos_sp.position.y = current_pose.pose.position.y;
    pos_sp.position.z = current_pose.pose.position.z;
}

void move_to_raw(int flag, float x, float y, float z, mavros_msgs::PositionTarget& pos_sp, ros::Publisher& position_setpoint_pub) {
    ros::Rate rate(20.0);
    pos_sp.position.x = x;
    pos_sp.position.y = y;
    pos_sp.position.z = z;
    while (!((fabs(current_pose.pose.position.x - pos_sp.position.x) < 0.05) && (fabs(current_pose.pose.position.y - pos_sp.position.y) < 0.05) && (fabs(current_pose.pose.position.z - pos_sp.position.z) < 0.05))) {
        avoid_crash(flag, pos_sp, position_setpoint_pub);
        position_setpoint_pub.publish(pos_sp);
        ros::spinOnce();
        rate.sleep();
    }

    match_with_curr(pos_sp);
    mission2_temp = current_pose;
}

void move_to_raw_without_avoid(float x, float y, float z, mavros_msgs::PositionTarget& pos_sp, ros::Publisher& position_setpoint_pub) {
    ros::Rate rate(20.0);
    pos_sp.position.x = x;
    pos_sp.position.y = y;
    pos_sp.position.z = z;
    while (!((fabs(current_pose.pose.position.x - pos_sp.position.x) < 0.05) && (fabs(current_pose.pose.position.y - pos_sp.position.y) < 0.05) && (fabs(current_pose.pose.position.z - pos_sp.position.z) < 0.05))) {
        position_setpoint_pub.publish(pos_sp);
        ros::spinOnce();
        rate.sleep();
    }
    mission2_temp = current_pose;
}

void do_yaw(float angle, mavros_msgs::PositionTarget& pos_sp, ros::Publisher& position_setpoint_pub) {
    ros::Rate rate(20.0);
    ros::Time last_request = ros::Time::now();
    pos_sp.yaw = angle;
    match_with_curr(pos_sp);
    while (ros::Time::now() - last_request < ros::Duration(4.0)) {
        position_setpoint_pub.publish(pos_sp);
        ros::spinOnce();
        rate.sleep();
    }
    move_to_raw_without_avoid(mission2_temp.pose.position.x, mission2_temp.pose.position.y, mission2_temp.pose.position.z, pos_sp, position_setpoint_pub);
}

bool m2_move (int flag1, int flag2, mavros_msgs::PositionTarget& pos_sp, ros::Publisher& position_setpoint_pub) {
    ros::Rate rate(20.0);
    int i = 0;
    if (flag1) {
        while ((depth_ind.data == "NO") && i < (2 / INCREMENT + 1) ) {
            switch(flag2) {
            case 1: { //1st side
                pos_sp.position.y -= INCREMENT;
                break;
            }
            case 2: { //2nd side
                pos_sp.position.x += INCREMENT;
                break;
            }
            case 3: { //3rd side
                pos_sp.position.y += INCREMENT;
                break;
            }
            case 4: { //4th side
                pos_sp.position.x -= INCREMENT;
                break;
            }
            }
            i++;
            if (i >= 2 / INCREMENT) {
                ROS_INFO("MOVED 2M");
                match_with_curr(pos_sp);
                return false;
            }
            avoid_crash(flag2, pos_sp, position_setpoint_pub);
            position_setpoint_pub.publish(pos_sp);
            ros::spinOnce();
            rate.sleep();
            
        }
    } else {
        while (depth_ind.data == "YES") {
            switch(flag2) {
            case 1: { //1st side
                pos_sp.position.x += INCREMENT;
                break;
            }
            case 2: { //2nd side
                pos_sp.position.y += INCREMENT;
                break;
            }
            case 3: { //3rd side
                pos_sp.position.x -= INCREMENT;
                break;
            }
            case 4: { //4th side
                pos_sp.position.y -= INCREMENT;
                break;
            }
            }

            avoid_crash(flag2, pos_sp, position_setpoint_pub);
            position_setpoint_pub.publish(pos_sp);
            ros::spinOnce();
            rate.sleep();
        }
    }
    match_with_curr(pos_sp);
    if (i <= 2/ INCREMENT) {
        return true;
    }
}


void mission2(mavros_msgs::PositionTarget& pos_sp, ros::Publisher& position_setpoint_pub, geometry_msgs::PoseStamped& pose, ros::Publisher& local_pos_pub) {
    ros::Rate rate(20.0);
    //1st half of 1st side
    move_to_raw(1,current_pose.pose.position.x, current_pose.pose.position.y - 2, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    m2_move(1, 1, pos_sp, position_setpoint_pub);
    move_to_raw_without_avoid(current_pose.pose.position.x, current_pose.pose.position.y - 0.5, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    do_yaw(PI / 2, pos_sp, position_setpoint_pub);
    m2_move(0,1, pos_sp, position_setpoint_pub);

    //2nd side
    move_to_raw(2, current_pose.pose.position.x + 4, current_pose.pose.position.y, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    m2_move(1, 2, pos_sp, position_setpoint_pub);
    move_to_raw_without_avoid( current_pose.pose.position.x + 0.5, current_pose.pose.position.y, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    do_yaw(PI, pos_sp, position_setpoint_pub);
    m2_move(0, 2, pos_sp, position_setpoint_pub);

    //3rd side
    move_to_raw(3, current_pose.pose.position.x, current_pose.pose.position.y + 4, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    m2_move(1, 3, pos_sp, position_setpoint_pub);
    move_to_raw_without_avoid( current_pose.pose.position.x, current_pose.pose.position.y + 0.5, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    do_yaw(PI * 1.5, pos_sp, position_setpoint_pub);
    m2_move(0, 3, pos_sp, position_setpoint_pub);

    //4th side
    move_to_raw(4, current_pose.pose.position.x - 4, current_pose.pose.position.y, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    m2_move(1, 4, pos_sp, position_setpoint_pub);
    move_to_raw_without_avoid( current_pose.pose.position.x - 0.5, current_pose.pose.position.y, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    do_yaw(PI * 2, pos_sp, position_setpoint_pub);
    m2_move(0, 4, pos_sp, position_setpoint_pub);

    //2nd half of 1st side
    move_to_raw(1, current_pose.pose.position.x, current_pose.pose.position.y - 2, current_pose.pose.position.z, pos_sp, position_setpoint_pub);
    
    move_to(mission2_center.pose.position.x, mission2_center.pose.position.y, 1.5, pose, local_pos_pub);
    move_to(mission2_center.pose.position.x, mission2_center.pose.position.y, 3, pose, local_pos_pub);
    move_to(mission2_center.pose.position.x + 6, mission2_center.pose.position.y, 3, pose, local_pos_pub);
    move_to(mission2_center.pose.position.x + 6, mission2_center.pose.position.y, 1.5, pose, local_pos_pub);
}



void landCb()
{
    land_cmd.request.yaw = 0;
    land_cmd.request.latitude = 0;
    land_cmd.request.longitude = 0;
    land_cmd.request.altitude = 0;
    
    land_client.call(land_cmd);
    if (land_cmd.response.success)
    {
        ROS_INFO("land command succeed");
    }
    else
    {
        ROS_ERROR("LAND Command Failed!");
    }
}


int main(int argc, char **argv)
{
    bool once = true;
    bool offb_enable = false;
    bool arm_enable = false; 
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
    ros::Subscriber uav_pose_sub = nh.subscribe<geometry_msgs::PoseStamped>(
        "/mavros/local_position/pose", 5,uavPoseCallback);
    ros::Subscriber marker_center_sub = nh.subscribe<geometry_msgs::Point>
            ("/M1/openmv/Gpos_center", 5, markerCenterCallback);
    ros::Subscriber marker_found_sub = nh.subscribe<geometry_msgs::Point>
            ("/M1/openmv/Gpos_max", 5, markerFoundCallback); 
    // ros::Subscriber marker_found_sub = nh.subscribe<std_msgs::String>
    //         ("/openmv/mission", 5, markerFoundCallback);    
    ros::Publisher servo_pub = nh.advertise<std_msgs::UInt16>("servo", 1);
    
    ros::Publisher position_setpoint_pub = nh.advertise<mavros_msgs::PositionTarget>
            ("/mavros/setpoint_raw/local", 10); //for yaw
    ros::Subscriber depth_ind_sub = nh.subscribe<std_msgs::String>
            ("M2/zed/depth_ind", 100, depthIndCallback);
    ros::Subscriber depth_val_sub = nh.subscribe<std_msgs::Float32>
            ("M2/zed/depth_val", 100, depthValCallback);
    land_client = nh.serviceClient<mavros_msgs::CommandTOL>
            ("/mavros/cmd/land");
    
    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 1.5;

    mavros_msgs::PositionTarget pos_sp;
    pos_sp.yaw = 0;

    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    while(ros::ok()){//from start to reaching 2m height
        if(!offb_enable && current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
                offb_enable = true;
            }
            last_request = ros::Time::now();
        } else {
            if( !arm_enable && !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                    arm_enable = true;
                }
                last_request = ros::Time::now();
            }
        }
        
       
        if (once && fabs(current_pose.pose.position.z - 1.5) < 0.05) {
            pose = current_pose;
            landCb();
            offb_enable = false;
            arm_enable = false;
            once = false;
        }
        local_pos_pub.publish(pose);

        ros::spinOnce();
        rate.sleep();
    }
    //mission 1
    /*
    std_msgs::UInt16 servo1;
    std_msgs::UInt16 servo2;
    std_msgs::UInt16 servo3;
    servo1.data = 1;
    servo2.data = 2;
    servo3.data = 3;

    while(ros::ok()) {
        move_to(mission1_center.pose.position.x, mission1_center.pose.position.y, 0.5, pose, local_pos_pub);
        
        go_and_drop(-1.4, -1.4, pose, local_pos_pub, servo1, servo_pub);
        go_and_drop(-1.4, 1.4, pose, local_pos_pub, servo2, servo_pub);
        go_and_drop(1.4, 1.4, pose, local_pos_pub, servo3, servo_pub);
        
        move_to(mission1_center.pose.position.x, mission1_center.pose.position.y, 2, pose, local_pos_pub);
        landCb();
        //TODO: find landing pad + land
        break;
    }

    //mission 2
    while(ros::ok()) {    
        findMarker(1, pose, local_pos_pub);
        adjust(pose, local_pos_pub, 40); //go to mission 2 point
        mission2_center = current_pose;

        for(int i = 0; i < 4; i ++) {
            m2_move(pose, local_pos_pub);
            at_corner(PI / 2, pose, pos_sp, local_pos_pub, position_setpoint_pub);
        }

        findMarker(2, pose, local_pos_pub);
        adjust(pose, local_pos_pub, 40);
        move_to(current_pose.pose.position.x + 3, current_pose.pose.position.y, current_pose.pose.position.z, pose, local_pos_pub);
        move_to(current_pose.pose.position.x, current_pose.pose.position.y + 5.5, current_pose.pose.position.z, pose, local_pos_pub);
        move_to(current_pose.pose.position.x - 3, current_pose.pose.position.y, current_pose.pose.position.z, pose, local_pos_pub);
        
        //TODO: find landing pad + land
        landCb();
        break;
    }
    */
    return 0;
}

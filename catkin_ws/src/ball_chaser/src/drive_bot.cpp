#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"
//TODO: Include the ball_chaser "DriveToTarget" header file

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities

bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,ball_chaser::DriveToTarget::Response& res)
{
	
	geometry_msgs::Twist motor_command;
	
	motor_command.linear.x = req.linear_x;
	motor_command.angular.z= req.angular_z;
	//Publish the linear and angular parameters 
	motor_command_publisher.publish(motor_command);

	return true;

}

int main(int argc,char** argv)
{
	ros::init(argc,argv,"drive_bot");
	ros::NodeHandle n;

	motor_command_publisher= n.advertise<geometry_msgs::Twist>("/cmd_vel",10);

	ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot",handle_drive_request);

	ros::spin();

	return 0;
}

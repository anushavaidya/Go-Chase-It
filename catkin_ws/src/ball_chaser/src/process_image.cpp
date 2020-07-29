#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>


ros::ServiceClient client;

void drive_robot(float lin_x,float ang_z)
{
	ball_chaser::DriveToTarget srv;
	
	srv.request.linear_x = lin_x;

	srv.request.angular_z = ang_z;

	if(!client.call(srv))
	{
		ROS_ERROR("Failed to call the service node");
	}
}

void process_image_callback(const sensor_msgs::Image img)
{
	int white_pixel = 255;
	bool ball_found;
	float img_size;
	int i;
	int row;
	//Initialize the ball_found as false 
	ball_found = false;
	//Find the area of the camera frame 
	img_size = img.height * img.step;

	for(i=0;i<img_size;i=i+3)
	{
		if(img.data[i]==white_pixel && img.data[i+1]==255 && img.data[i+2]==white_pixel)
		{
			ball_found = true;
			row = i % img.step;
			if(row < img.step/3)
			{
				//Make a left turn 
				drive_robot(0.0,0.2);
				break;
			}
			else if(row>img.step *2/3)
			{
				//Make a right turn 
				drive_robot(0.0,-0.2);	
				break;		
			}
			else
			{
				//Go forward 
				drive_robot(0.3,0.0);			
			}
		}	
	}
	//If there is no ball in the frame, the robot should stay still
	if(ball_found==false)
	{
		drive_robot(0.0,0.0);	
	}
	
	

}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}

# Go-Chase-It!
Project 2 of Udacity's Robotics Software Engineering Nanodegree Program 

## Overview of the project 
In this project, I created two ROS packages drive_bot and ball_chaser. The details regarding the packages are given below.
1) drive_bot 
* Create a my_robot ROS package to hold your robot, the white ball, and the world.
* Design a differential drive robot with the Unified Robot Description Format. Add two sensors to your robot: a lidar and a camera. Add Gazebo plugins for your robot’s differential drive, lidar, and camera. The robot you design should be significantly different from the one presented in the project lesson. Implement significant changes such as adjusting the color, wheel radius, and chassis dimensions. Or completely redesign the robot model!
* House your robot inside the world you built in the Build My World project.
* Add a white-colored ball to your Gazebo world and save a new copy of this world.
* The world.launch file should launch your world with the white-colored ball and your robot.

2) ball_chaser 
* Create a ball_chaser ROS package to hold your C++ nodes.
* Write a drive_bot C++ node that will provide a ball_chaser/command_robot service to drive the robot by controlling its linear x and angular z velocities. The service should publish to the wheel joints and return back the requested velocities.
* Write a process_image C++ node that reads your robot’s camera image, analyzes it to determine the presence and position of a white ball. If a white ball exists in the image, your node should request a service via a client to drive the robot towards it.
* The ball_chaser.launch should run both the drive_bot and the process_image nodes.

## What you will need to run
* Gazebo >= 7.0
* ROS Kinetic
* make >= 4.1 (Is installed by default on most Linux distros)

## Project Description 
Directory Structure 


## How to run 

* Clone this repository
* Open the repository and make 
cd /home/workspace/catkin_ws/
catkin_make
* Launch my_robot in Gazebo to load both the world and plugins 
roslaunch my_robot world.launch
* Launch ball_chaser and process_image nodes 
cd /home/workspace/catkin_ws/
source devel/setup.bash
roslaunch ball_chaser ball_chaser.launch
* Visualize 
cd /home/workspace/catkin_ws/
source devel/setup.bash
rosrun rqt_image_view rqt_image_view  


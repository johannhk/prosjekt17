//MISC
#include <sstream>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//ROS specific
#include "ros/ros.h"
#include <ros/callback_queue.h>
#include "std_msgs/String.h"
//Custom ROS messages and headers
#include "trollnode/Expression.h"
#include "trollnode/expression_class.h"
//#include "trollnode/expression_templates.h"




int count = 0;


void set_message(trollnode::Expression *msg)
{
	std::stringstream ss;
	switch(count)
	{
		case 0: case 1 : case 2:
			//sprintf(value, "nummer %i", count);
			ss << "nummer" << count;
			msg->speech= ss.str();
			msg->expression= ss.str();
			msg->look = ss.str();
			count++;
			return;
		default:
			count = 0;
			return;
	}
}


int main(int argc, char **argv)
{
	trollnode::Expression msg;
	//calling ROS functions to initialize the node
	ros::init(argc, argv, "publishExpression");
	ros::NodeHandle n;


	ros::Publisher expressionPublisher = n.advertise<trollnode::Expression>("expression_topic", 100);
	ros::Rate loop_rate(0.2);
	//std::string action = set_message();
	while(ros::ok())
	{
		
		set_message(&msg);

		expressionPublisher.publish(msg);
		ROS_INFO("sent message %s", msg.speech.c_str());

		ros::spinOnce();
		loop_rate.sleep();

	}
	return 0;


}
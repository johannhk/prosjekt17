//MISC
#include <sstream>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//ROS files
#include "ros/ros.h"
#include <ros/callback_queue.h>
//headerfiles
#include "estimate_interest/person.h"

void updatePositions(estimate_interest::PersonsArray* msg)
{
	estimate_interest::PersonInfo person;
	for (int i=0;i<3;i++)
	{
		person.id=i+2;
		person.x=i;
		person.y=i;
		msg->persons.push_back(person);
	}
}


//int main(int argc, char** argv)
int main(int argc, char** argv)
{
	//initializing node and rate
	ros::init(argc, argv, "lookingNode");
	ros::NodeHandle n;
	ros::Publisher lookPublisher = n.advertise<estimate_interest::PersonsArray>("persons_information", 10);
	ros::Rate loop_rate(0.2);

	//estimate_interest::PersonInfo persons;
	estimate_interest::PersonsArray arr;

	while(ros::ok())
	{
		updatePositions(&arr);
		lookPublisher.publish(arr);
		ROS_INFO("Sent message with array");

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;

}
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


/*this function should be replaced when a camera with human detection for the cyborg
is ready and position and personID can be read from there*/
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

int main(int argc, char** argv)
{
	//initializing publisher node of personID and positions for tracked objects
	ros::init(argc, argv, "lookingNode");
	ros::NodeHandle n;
	ros::Publisher lookPublisher = n.advertise<estimate_interest::PersonsArray>("persons_information", 10);
	ros::Rate loop_rate(1);

	estimate_interest::PersonsArray arr;


	while(ros::ok())
	{
		updatePositions(&arr);
		lookPublisher.publish(arr);
		ROS_INFO("Sent PersonArray");

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;

}
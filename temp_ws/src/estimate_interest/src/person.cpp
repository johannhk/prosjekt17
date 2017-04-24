//headerfiles
#include "estimate_interest/person.h"
//ROS SPECIFIC
#include "ros/ros.h"


double Position::get_distance_cyborg()
{
	double dist=sqrt(pow(pos_x, 2)+pow(pos_y,2));
	return dist;
}

Position Person::get_position()
{
	int size=positions.size();
	return positions[size-1];
}

int main(int argc, char** argv)
{

	ros::init(argc, argv, "classifyPersons")
	ros::NodeHandle n;
	ros::Subscriber classifyPerson = n.subscribe("persons_information", 100, )

	//std::cout<<"current position is"<<person1.get_position().get_distance_cyborg()	;

}
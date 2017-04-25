//headerfiles
#include "estimate_interest/person.h"
//ROS SPECIFIC
#include "ros/ros.h"
#include <ros/callback_queue.h>


double Position::getDistanceCyborg()
{
	double dist=sqrt(pow(this->x, 2)+pow(y,2));
	return dist;
}

Position Person::getPosition()
{
	//int size=positions.size();
	//return positions[size-1];
}
void Person::print()
{
	ROS_INFO("Initiating %i", id);
	return;
}

void PersonList::updatePersons(const estimate_interest::PersonsArray::ConstPtr& msg)
{
	int numPersons = msg->persons.size();
	ROS_INFO("SIZE IS %i", 0);
	for (int i=0; i<numPersons; i++)
	{
		Position pos(msg->persons[i].x, msg->persons[i].y, 2.0);
		Person person(msg->persons[i]);
		persons.push_back(person);
		person.print();

	}

	return;
}


int main(int argc, char** argv)
{
	ROS_INFO("START");
	ros::init(argc, argv, "classifyPersons");
	ros::NodeHandle n;

	//std::vector<Person>* persons;
	PersonList persons;
	//creating callback function updatePersons on object persons
	ros::Subscriber classifyPerson = n.subscribe("persons_information", 10, &PersonList::updatePersons, &persons);

	ros::spin();


	//std::cout<<"current position is"<<person1.get_position().get_distance_cyborg()	;
}
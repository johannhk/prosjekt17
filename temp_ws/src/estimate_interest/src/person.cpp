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

double Position::getDistanceToPoint(Position position)
{
	return sqrt(pow(this->x-position.x, 2)+pow(this->y-position.y, 2));
}

double Position::getTimeDifference(Position position)
{
	return (this->time-position.time);
}

void Position::print()
{
	ROS_INFO("Position is x = %.3f, y = %.3f", x, y);
	return;
}

Position Person::getPosition()
{
	return positions.back();
}

void Person::setSpeed()
{
	if(2<=positions.size())
	{
		double dist = positions.back().getDistanceToPoint(positions.end()[-2]);
		speed = dist/positions.back().getTimeDifference(positions.end()[-2]);
	}
}

void Person::setStatus()
{
	double stationary_threshold = 0.08;
	if (positions.size()<=1)
	{
		status=Person::Status::INIT;
		print();
		return;
	}
	//find current distance
	int cur_dist = positions.back().getDistanceCyborg();
	int prev_dist = positions.end()[-2].getDistanceCyborg();
	setSpeed();

	/*Classifies person's status based on their position, speed and walking direction
	, needs to be tweaked after the camera is operational*/
	if (cur_dist < SOCIAL_DISTANCE && speed < STATIONARY_SPEED)
	{
		status=Person::Status::INTERESTED;
	}
	else
		status=Person::Status::INTERESTED;
	//else if(cur_dist < PUBLIC_DISTANCE &&  )
}

void Person::print()
{
	ROS_INFO("Initiating %i", id);
	return;
}

void PersonList::updatePersons(const estimate_interest::PersonsArray::ConstPtr& msg)
{
	ROS_INFO("SIZE IS %i", msg->persons.size());
	for (int i=0; i<msg->persons.size(); i++)
	{
		Position pos(msg->persons[i].x, msg->persons[i].y, 2.0);
		Person person(msg->persons[i]);
		person.setStatus();
		persons.push_back(person);
		person.print();
	}
	return;
}



void PersonList::setMessage(estimate_interest::DirectionStatus& msg)
{
	msg.interested=false;
	//loop through list of person to find potentional interested
	for(int i=0;i<persons.size(); i++) {
		if(persons[i].getStatus() > Person::Status::INTERESTED) {
			ROS_INFO("INTERESTED PERSON FOUND");
			msg.interested = true;
			switch(persons[i].dir)
			{
				case Person::Direction::RIGHT:
					msg.direction = "right";
					continue;
				case Person::Direction::LEFT:
					msg.direction = "left";
					continue;
				case Person::Direction::FRONT:
					msg.direction = "front";
					continue;
			}
		}
	}

}


int main(int argc, char** argv)
{
	ROS_INFO("START");
	ros::init(argc, argv, "classifyPersons");
	ros::NodeHandle n;

	//std::vector<Person>* persons;
	PersonList persons;
	//creating callback function updatePersons for perceived persons
	ros::Subscriber classifyPerson = n.subscribe("persons_information", 10, &PersonList::updatePersons, &persons);
	//creating publisher node sending direction and whether interested to expressionNode
	ros::Publisher dirPublisher = n.advertise<estimate_interest::DirectionStatus>("send_expression", 10);
	ros::Rate loop_rate (0.2);

	//sendDirection and greetings
	estimate_interest::DirectionStatus msg;
	while(ros::ok())
	{
		persons.setMessage(msg);
		dirPublisher.publish(msg);

		ros::spinOnce();
		loop_rate.sleep();
	}
	
	ros::spin();
	//std::cout<<"current position is"<<person1.get_position().get_distance_cyborg();
}
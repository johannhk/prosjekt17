//headerfiles
#include "estimate_interest/person.h"
//ROS SPECIFIC


float Position::getDistanceCyborg()
{
	float dist=sqrt(pow(this->x, 2)+pow(y,2));
	return dist;
}

double Position::getDistanceToPoint(Position position)
{
	return sqrt(pow(this->x-position.x, 2)+pow(this->y-position.y, 2));
}

//returns seconds elapsed in float type
double Position::getTimeDifference(Position position)
{

	return (this->time - position.time).toSec();
}

void Position::print()
{
	ROS_INFO("Position is x = %i, y = %i", x, y);
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
		//find distance between the two last tracked points
		double dist = positions.back().getDistanceToPoint(positions.end()[-2]);
		//find time interval between the two last tracked points
		double secs = positions.back().getTimeDifference(positions.end()[-2]);
		speed = dist/secs;
	}
}
void Person::setDirection()
{

	return;
}

//!!!!!!!!!!!!!!!!!!!NOT FINISHED
void Person::setStatus()
{
	double stationary_threshold = 0.08;
	if (positions.size()<=1)
	{
		status=Person::Status::INIT;
		//print();
		return;
	}

	//find current distance
	float cur_dist = positions.back().getDistanceCyborg();
	float prev_dist = positions.end()[-2].getDistanceCyborg();
	setSpeed();

	/*Classifies person's status based on their position, speed and walking direction*/
	if (cur_dist < SOCIAL_DISTANCE && speed < STATIONARY_SPEED)
	{
		status=Person::Status::INTERESTED;
	}
	else
		status=Person::Status::NOT_INTERESTED;
	//else if(cur_dist < PUBLIC_DISTANCE &&  )
}

void Person::print()
{
	ROS_INFO("Initiating %i", id);
	return;
}

void PersonList::updatePersons(const estimate_interest::PersonsArray::ConstPtr& msg)
{
	ROS_INFO("%i persons found, %i persons already tracked", msg->persons.size(), persons.size());

	bool tracked;
	for (int i = 0; i < msg->persons.size(); i++) {
		tracked = false;
		Position pos(msg->persons[i]);
		for(int j = 0; j < persons.size(); j++) {
			if (msg->persons[i].id == this->persons[j].id) {
				tracked = true;
				persons[j].positions.push_back(pos);
			}	
		}
		if (!tracked) {
			Person person(msg->persons[i]);
			person.setStatus();
			persons.push_back(person);
			ROS_INFO("NEW ID IS %i", msg->persons[i].id);
		}
	}
	return;
}

void PersonList::setMessage(estimate_interest::DirectionStatus& msg) {
	msg.interested=false;
	//loop through list of person to find potentional interested
	for(int i=0;i<persons.size(); i++) {
		if( persons[i].getStatus() == Person::Status::INTERESTED || 
			persons[i].getStatus() == Person::Status::INIT) {
			ROS_INFO("INTERESTED PERSON FOUND");
			msg.interested = true;
			switch(persons[i].dir) {
				case Person::Direction::RIGHT:
					msg.direction = "right";
					continue;
				case Person::Direction::LEFT:
					msg.direction = "left";
					continue;
				case Person::Direction::FRONT:
					msg.direction = "front";
					continue;
				default:
					msg.direction = "front";
			}
		}
	}
	//ROS_INFO("sent DIRSTATUS dir: %s, bool: %B", msg.direction.str(), msg.interested);
	ROS_INFO_STREAM(msg);
	personPub.publish(msg);

}

void PersonList::sendMessage(estimate_interest::DirectionStatus& msg) {



	return;
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "classifyPersons");
	ros::NodeHandle n;

	PersonList persons;
	
	//callback function updatePersons for perceived persons
	//ros::Subscriber classifyPerson = n.subscribe("persons_information", 10, &PersonList::updatePersons, &persons);	
	//publisher node sending direction and status
	//ros::Publisher dirPublisher = n.advertise<estimate_interest::DirectionStatus>("direction_and_status", 10);
	//ros::Timer publishTimer = nh.createTimer(ros::Duration(1.0), ros::PersonList::sendMessage&, persons);
	ros::Rate loop_rate (1);

	estimate_interest::DirectionStatus msg;
	//ros::spin();
	while(ros::ok())
	{
		loop_rate.sleep();
		ros::spinOnce();
		persons.setMessage(msg);
	}
	
	//std::cout<<"current position is"<<person1.get_position().get_distance_cyborg();
}
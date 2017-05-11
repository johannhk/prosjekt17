#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

// dependencies
#include <math.h>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "ros/ros.h"
#include <ros/callback_queue.h>
//Custom message files from /msg
#include "estimate_interest/PersonInfo.h"
#include "estimate_interest/PersonsArray.h"
#include "estimate_interest/DirectionStatus.h"

#define SOCIAL_DISTANCE 2.5
#define PUBLIC_DISTANCE 3.5
#define FAST_SPEED 0.8
#define STATIONARY_SPEED 0.2
#define UPDATE_RATE 1

//using carthesian coordinates where origo is current position of cyborg
class Position{
	int x;
	int y;
	float time;

public:
	//constructors
	Position(){}
	//!!!!Cant call from callback function
	Position(estimate_interest::PersonInfo msg) 
		: x(msg.x)
		, y(msg.y) 
	{}
	/*Position(estimate_interest::PersonInfo::ConstPtr& msg) 
		: x(msg->x)
		, y(msg->y) 
	{}*/
	Position(int x, int y, double ros_time) 
		: x(x)
		, y(y)
		, time(time) 
	{}

	void print();
	float getDistanceCyborg();
	double getTimeDifference(Position position);
	double getDistanceToPoint(Position position);

};

class PersonList;

class Person{
	friend class PersonList;
private:
	enum class Status {
	INTERESTED,
	HESITATING,
	INDECISIVE,
	NOT_INTERESTED,
	INIT
	};
	enum class Direction{
	RIGHT,
	LEFT,
	FRONT
	};



	//ros::Timer publishTimer = nh.createTimer(ros::Duration(1.0), ros::PersonList::sendMessage&, this);

	int id;
	std::vector<Position> positions;
	double speed;
	Status status;
	Direction dir;
public:
	//constructors
	Person(){}
	Person(estimate_interest::PersonInfo msg)
		: id(msg.id)
		, positions(1, Position(msg))
		, speed(0.0)
		, status(static_cast<Person::Status>(5)) 
		
	{}
	//member functions
	void print();
	void setSpeed();
	void addPosition(Position pos) { positions.push_back(pos); }
	void setStatus();
	void setDirection();


	Position getPosition();
	Status getStatus(){ return status;}
	Direction getDirection(){return dir;}




};


class PersonList{

	std::vector<Person> persons;

	//ROS Subscriber and Publisher member
	ros::NodeHandle personNh;
	ros::Subscriber personSubscriber;
	ros::Publisher personPublisher;
public:
	void updatePersons(const estimate_interest::PersonsArray::ConstPtr& msg);

	//constructors
	PersonList() 
		: persons()
		, personSubscriber(personNh.subscribe("persons_information", 10, &PersonList::updatePersons, this))
		, personPublisher(personNh.advertise<estimate_interest::DirectionStatus>("direction_and_status", 10))
	{}
	
	void updatePositions();
	void updateStatus();

	void setMessage(estimate_interest::DirectionStatus& msg);
	void sendMessage(estimate_interest::DirectionStatus& msg);
};




#endif // __PERSON_H_INCLUDED__ 

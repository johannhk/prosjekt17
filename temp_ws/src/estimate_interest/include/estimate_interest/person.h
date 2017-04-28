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





//print status by overloading?????

//using carthesian coordinates with origo for current position of cyborg
class Position{
	int x;
	int y;
	double time;

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
	double getDistanceCyborg();
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
	//enum class Direction 
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
	Position getPosition();
	void setSpeed();
	void addPosition(Position pos) { positions.push_back(pos); }
	void setStatus();
	void setDirection();

	Status getStatus(){ return status;}
	Direction getDirection(){return dir;}




};


class PersonList{

	std::vector<Person> persons;
public:
	//constructors
	PersonList() : persons(){}
	void updatePersons(const estimate_interest::PersonsArray::ConstPtr& msg);
	void updatePositions();
	void updateStatus();
	void setMessage(estimate_interest::DirectionStatus& msg);
};




#endif // __PERSON_H_INCLUDED__ 

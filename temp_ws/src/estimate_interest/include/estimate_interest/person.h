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

//using weak typed to easier send across ROS
enum Status {
	Interested,
	Not_interested,
	Hesitating,
	Indecisive,
	Init,
	NotTracked
};

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
	Position(estimate_interest::PersonInfo msg) : x(msg.x), y(msg.y) {}
	//Position(estimate_interest::PersonInfo::ConstPtr& msg) : x(msg->x), y(msg->y) {}
	Position(int x, int y, double ros_time) : x(x), y(y), time(time){}


	double getDistanceCyborg();
};

class Person{
	int id;
	std::vector<Position> positions;
	int status;

public:
	//constructors
	Person(){}

	//!!!!!!!!!!construct with int and typecase to enum Status
	Person(estimate_interest::PersonInfo msg): id(msg.id), positions(1, Position(msg)), status(msg.status){}
	//member functions
	void print();	
	Position getPosition();
	void addPosition(Position pos);
	void setStatus();
	int getStatus(){ return status;}
};


class PersonList{
	std::vector<Person> persons;
public:
	//constructors
	PersonList() : persons(){}
	void updatePersons(const estimate_interest::PersonsArray::ConstPtr& msg);
	void updatePositions();
	void updateStatus();
};




#endif // __PERSON_H_INCLUDED__ 

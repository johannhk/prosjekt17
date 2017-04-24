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

//enum classes - enumerator names are local to the enum and their values do not implicitly convert to other t
enum Status {
	Interested,
	Not_interested,
	Hesitating,
	Indecisive,
	Init
};

//print status by overloading?????

//using carthesian coordinates with origo for current position of cyborg
class Position{
	int pos_x;
	int pos_y;
	double pos_time;
public:
	Position(){}
	Position(estimate_interest::PersonInfo msg, double ros_time)
	{
		pos_x = msg.x;
		pos_y = msg.y;
		pos_time=ros_time;

	}
	double get_distance_cyborg();
};

class Person{
	int number;
	std::vector<Position> positions;
	Status status;

public:
	//constructors
	Person(){}
	Person(int person_number, Status start_status, Position start_pos)
	{
		number=person_number;
		status=start_status;
		//positions(1, Position start_pos);
		std::vector<Position>temp(1, start_pos);
		positions=temp;
	}
	//!!make empty option
	Position get_position();
	//!!make empty option
	Status get_status(){ return status;}

};

#endif // __PERSON_H_INCLUDED__ 

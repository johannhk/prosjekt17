#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

// dependencies
#include <math.h>
#include <vector>
#include <stdio.h>


//Message files
#include "geometry_msgs/Point.h"

//enum classes - enumerator names are local to the enum and their values do not implicitly convert to other t
enum class Status {
	Interested,
	Not_interested,
	Hesitating,
	Indecisive,
	Init
};

//print status by overloading?????


class::Position{
	int pos_x;
	int pos_y;
	double time;
public:
	Position(){}
	Position(geometry_msgs::Point position, double ros_time)
	{
		pos_x = position.x;
		pos_y = position.y;
		time=ros_time;

	}
	double get_distance_cyborg();
};

class::Person{
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
		positions(1, Position start_pos);
		//std::vector<Position>temp(1, Position start_pos);
		//positions=temp;
	}
	//!!make empty option
	Position get_position(){return pos};
	//!!make empty option
	Status get_status(){ return status;}

}

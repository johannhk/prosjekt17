#ifndef __EXPRESSION_H_INCLUDED__
#define __EXPRESSION_H_INCLUDED__


#include <vector>
#include <tuple>

#include <string.h>
//Custom ROS messages and headers(Messages are in uppercase)
//#include "trollnode/expression_templates.h"
#include "estimate_interest/DirectionStatus.h"
#include "speech_processing/Expression.h"

struct actionUnit
{
	int AU;
	float startTime;
	float startIntensity;
	float stopTime;
	float stopIntensity;
};



class Expression
{
	//actionUnit lookDirection;

	std::string lookDir;
	std::string emotion;
	std::string speech;
	std::vector<actionUnit> actions;

public:
	//NEED CONSTRUCTIORS
	Expression(){};
	void addActions(std::string expr);
	void addLookDirection(const estimate_interest::DirectionStatus::ConstPtr& msg);
	void addSpeech(const speech_processing::Expression::ConstPtr& msg);
	void relaxExpression(Expression previous);
	std::string translateToString();
	std::string createExpression(Expression previous);
	//void sendString(int socket_id, std::string msgString);

};

#endif // __EXPRESSION_H_INCLUDED__
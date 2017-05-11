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

	//ROS subcribers for topics influencing the trollface
	ros::NodeHandle exprNh;
	ros::Subscriber dirSub;
	ros::Subscriber speechSub ;
	ros::Subscriber emotionSub;
	ros::Timer sendTimer;

	std::string lookDir;
	std::string emotion;
	std::string speech;

	std::vector<actionUnit> actions;



public:
	Expression()
		: dirSub(exprNh.subscribe("direction_and_status", 10, &Expression::addLookDirection, this))
		, speechSub(exprNh.subscribe("speech_topic", 10, &Expression::addSpeech,this))
		, emotionSub()
		, sendTimer(exprNh.createTimer(ros::Duration(4.0), &Expression::sendString, this))
	{}

	void sendString(const ros::TimerEvent& timer);
	void addActions(std::string expr);
	void addLookDirection(const estimate_interest::DirectionStatus::ConstPtr& msg);
	void addSpeech(const speech_processing::Expression::ConstPtr& msg);
	void relaxExpression(Expression previous);
	std::string translateToString();
	std::string createExpression(Expression previous);
	

};

#endif // __EXPRESSION_H_INCLUDED__
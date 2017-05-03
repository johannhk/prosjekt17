#ifndef __EXPRESSION_CLASS_H_INCLUDED__
#define __EXPRESSION_CLASS_H_INCLUDED__


#include <vector>
#include <string.h>
//Custom ROS messages and headers(Messages are in uppercase)
//#include "trollnode/expression_templates.h"
#include "estimate_interest/DirectionStatus.h"
#include "speech_processing/Expression.h"

struct actionUnit
{
	int AU;
	double intensity;
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
	std::string createExpressionString();

};


class ExprQueue
{
	std::vector<Expression> expressions;
public:
	ExprQueue(){};
	
	void addExpression(Expression expr);
	//void ignoreExpression();


	void sendExpression();
};

#endif // __EXPRESSION_CLASS_H_INCLUDED__
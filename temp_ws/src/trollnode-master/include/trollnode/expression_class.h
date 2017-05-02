#ifndef __EXPRESSION_CLASS_H_INCLUDED__
#define __EXPRESSION_CLASS_H_INCLUDED__


#include <vector>
#include "trollnode/expression_templates.h"
#include "estimate_interest/DirectionStatus.h"
#include "speech_processing/Expression.h"


//!!!!!NOT USED AS OF NOW
enum class LookDirection {
	Up,
	Down,
	Left,
	Right,
	Neutral
};


class Expression
{
	std::vector<actionUnit> actions;
	std::string speech;

public:
	//NEED CONSTRUCTIORS
	Expression(){};
	void addLookDirection(const estimate_interest::DirectionStatus& msg);
	//void setRecvExpr(trollnode::Expression msg);
	void setSpeech(const speech_processing::Expression& msg);
	std::string createExpressionString();

};


class ExprQueue
{
	std::vector<Expression> expressions;
public:
	ExprQueue(){};

	//Need to figure out when/how to send
	void sendExpression();
	void addExpression(Expression expr);
	void ignoreExpression();
};

#endif // __EXPRESSION_CLASS_H_INCLUDED__
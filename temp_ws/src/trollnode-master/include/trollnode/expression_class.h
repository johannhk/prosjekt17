#ifndef __EXPRESSION_CLASS_H_INCLUDED__
#define __EXPRESSION_CLASS_H_INCLUDED__


#include <vector>
#include "trollnode/expression_templates.h"


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

	void setRecvExpr(trollnode::Expression msg);
	std::string getActionName();

};


class ExprQueue
{
	std::vector<Expression> exprQueue;
public:
	//NEED CONSTRUCTORS

	void sendExpression();
	void addExpression(const trollnode::Expression::ConstPtr& msg);
	void ignoreExpression();
};

#endif // __EXPRESSION_CLASS_H_INCLUDED__
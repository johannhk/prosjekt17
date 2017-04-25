#include "trollnode/expression_templates.h"



class Expression
{

	int actionSize;
	actionUnit actions[];
	std::string speech;


public:
	//NEED CONSTRUCTIORS
	std::string getActionName();

};


class ExprQueue
{
public:
	//NEED CONSTRUCTORS

	void sendExpression();
	void addExpression(const trollnode::Expression::ConstPtr& msg);
	void ignoreExpression();
private:
	int current_length;
	int max_length;
	Expression buffer[];
};

/*actionUnit* set_current_expression(const std::string & expression)
{
	static std::map< std::string, actionUnit * > lookup = {
		{ "angry", angry },
		{ "smile", smile },
		{ "neutral", neutral},
		{ "happy", happy },
		{ "sad", sad },
		{ "surprise", surprise },
		{ "suspicious", suspicious },
		{ "disgust", disgust },
		{ "pain", pain },
	};

	if (expression.compare("") != 0) {
		auto it = lookup.find(expression);
		if (it != lookup.end()) {
			return it->second;
		} else {
			ROS_ERROR("Did not recognize expression [%s], current expression not changed.",expression.c_str());
			return NULL;
		}
	}
	return NULL;
}*/
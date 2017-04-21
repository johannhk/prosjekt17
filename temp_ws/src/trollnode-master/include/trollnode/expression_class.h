#include "trollnode/expression_templates.h"



class Expression
{
public:
	std::string getActionName();
private:
	int action_size;
	actionUnit actions[];
	std::string speech;
};


class ExprQueue
{
public:
	void send_expression();
	void add_expression(const trollnode::Expression::ConstPtr& msg);
	void ignore_expression();
private:
	int current_length;
	int max_length;
	Expression buffer[];
};


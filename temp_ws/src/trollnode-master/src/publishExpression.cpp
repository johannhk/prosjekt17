//MISC
#include <sstream>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//ROS specific
#include "ros/ros.h"
#include <ros/callback_queue.h>
#include "std_msgs/String.h"
//Custom ROS messages and headers(Messages are in uppercase)
#include "trollnode/Expression.h"
#include "trollnode/expression_class.h"
#include "trollnode/expression_templates.h"

int count = 0;
//std::string Expression::getActionName()

//this function sets an expression to what has been recived over ROS
void Expression::setRecvExpr(trollnode::Expression msg)
{
	//map to translate strings from to actionunits being sent to the trollface
	static std::map< std::string, std::vector<actionUnit> > lookup = {
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



	//setting actions to vector<actionUnit> corrensponding to the recieved expression
	if (msg.expression.compare("") != 0) {
		auto it = lookup.find(msg.expression);
		if (it != lookup.end()) {
			actions.push_back(it->second);
		} else {
			ROS_ERROR("Did not recognize expression [%s], current expression not changed.",msg.expression.c_str());
			//actions = NULL;
		}
	}

	//appending the expression with looking direction
	if (msg.look.compare("") != 0) {
		auto it = lookup.find(msg.expression);
		if (it != lookup.end()) {
			//appending looking direction to the expression vector, as both is to be sent the face
			actions.insert(actions.end(), it->second.begin(), it->second.end());
		} else {
			ROS_ERROR("Did not recognize direction [%s], current direction not changed.",msg.look.c_str());
			//actions = NULL;
		}
	}
	speech = msg.speech;


}



void setMessage(trollnode::Expression *msg)
{
	std::stringstream ss;
	switch(count)
	{
		case 0: case 1 : case 2:
			ss << "nummer" << count;
			msg->speech= ss.str();
			msg->expression= ss.str();
			msg->look = ss.str();
			count++;
			return;
		default:
			count = 0;
			return;
	}
}

int main(int argc, char **argv)
{
	//calling ROS functions to initialize the node
	ros::init(argc, argv, "publishExpression");
	ros::NodeHandle n;
	ros::Publisher expressionPublisher = n.advertise<trollnode::Expression>("expression_topic", 100);
	ros::Rate loop_rate(0.2);
	
	trollnode::Expression msg;
	while(ros::ok())
	{
		
		setMessage(&msg);

		expressionPublisher.publish(msg);
		ROS_INFO("sent message %s", msg.speech.c_str());

		ros::spinOnce();
		loop_rate.sleep();

	}
	return 0;


}
/**
	Node for testing the trollface. Sends messages with expressions, speech and directions at fixed intervalls.

	Publishes to:
		- trollExpression


*/


#include "ros/ros.h"

//ROS message files
#include "trollnode/Expression.h"

//Other
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sstream>

//ROS topic names
std::string expression_topic_name = "trollExpression";

bool test_cycle = true;
bool test_repeat = false;
bool test_presentation = false;

float sec_between_msg = 7;


int main(int argc, char **argv)
	{

	ros::init(argc, argv, "publishExpression");

	ros::NodeHandle n;

	ros::Publisher expression_command = n.advertise<trollnode::Expression>(expression_topic_name, 3); 
	ros::Rate loop_rate(1/sec_between_msg);


	int i = 1;


	while (ros::ok())
	{

		trollnode::Expression expr_msg;


		if (test_repeat)
		{
			expr_msg.expression = "happy";
			expr_msg.speech = "";
			//expr_msg.speech = "Hello, It is nice to meet you. I am a troll, and I look forward to a good career here. Goodbye and Sleep tight.";

			expr_msg.look = "";
		}
		else if (test_presentation)
		{
			
			expr_msg.expression = "neutral";
			expr_msg.speech = "I will now start the presentation.";
			expr_msg.look = "neutral";
			expression_command.publish(expr_msg);
			ros::Duration(5).sleep();

			expr_msg.expression = "smile";
			expr_msg.speech = "Good morning. I am the Trollface, the soon to be face of a Cyborg.";
			expr_msg.look = "neutral";
			expression_command.publish(expr_msg);
			ros::Duration(5).sleep();



			expr_msg.expression = "sad";
			expr_msg.speech = "It have not been an easy journey. There have been many seatbacks and unexpected problems.";
			expr_msg.look = "down";
			expression_command.publish(expr_msg);
			ros::Duration(7).sleep();


			expr_msg.expression = "happy";
			expr_msg.speech = "But now things are looking much better. You can see for yourself how good I am at doing face things.";
			expr_msg.look = "neutral";
			expression_command.publish(expr_msg);
			ros::Duration(5).sleep();


			expr_msg.expression = "angry";
			expr_msg.speech = "It makes me angry thinking about those who doubted me, but I think we all know who got the last laugh.";
			expr_msg.look = "left";
			expression_command.publish(expr_msg);
			ros::Duration(8).sleep();


			expr_msg.expression = "neutral";
			expr_msg.speech = "I look forward to working with you. That's all, folks.";
			expr_msg.look = "neutral";
			expression_command.publish(expr_msg);
			ros::Duration(8).sleep();

		}
		else if(test_cycle)
		{



			if (i == 1)
			{
				expr_msg.expression = "angry";
				expr_msg.speech = "Why did you make me so angry?";
				expr_msg.look = "left";
			}
			else if (i == 2)
			{
				expr_msg.expression = "smile";
				//expr_msg.speech = "Cheeze";
				expr_msg.speech = "";
				expr_msg.look = "right";
			}
			else if (i == 3)
			{
				//expr_msg.expression = "sad";
				expr_msg.expression = "";
				expr_msg.speech = "Aw, that's very sad.";
				expr_msg.look = "left";
			}
			else if (i == 4)
			{
				expr_msg.expression = "disgust";
				//expr_msg.speech = "I am now super disgusted, and I will express my disgust over an exceedingly long amount of time. My disgust is beyond all reasonableness, and no one around me will escape me expressing this.";
				expr_msg.speech = "yuck, very disgusting";
				expr_msg.look = "down";
			}
			else if (i == 5)
			{
				expr_msg.expression = "surprise";
				expr_msg.speech = "Gah, that scared me very much.";
				expr_msg.look = "left";
			}
			else if (i == 6)
			{
				expr_msg.expression = "fear";
				expr_msg.speech = "I am now super scared";
				expr_msg.look = "right";
			}
			else if (i == 7)
			{
				expr_msg.expression = "suspicious";
				expr_msg.speech = "I don't like the look of you. Get out of here now. We don't take kindly to your type of people around here.";
				expr_msg.look = "up";
			}
			else if (i == 8)
			{
				expr_msg.expression = "neutral";
				expr_msg.speech = "Back to business.";
				expr_msg.look = "neutral";
			}
			else if (i == 9)
			{
				expr_msg.expression = "pain";
				expr_msg.speech = "Auch, it hurts so much. Why did you do that?";
				expr_msg.look = "right";
			}
			else if (i == 10)
			{
				expr_msg.expression = "duckface";
				expr_msg.speech = "I'm so pretty!";
				expr_msg.look = "neutral";

			}
			else
			{
				i = 0;
				expr_msg.expression = "happy";
				expr_msg.speech = "I'm very glad to have friends like you around. it makes things much better.";
				expr_msg.look = "up";
			} 

			//expr_msg.look = "";

			i = i + 1;
		}

		ROS_INFO("Expression: [%s], Speech: [%s], Look: [%s]", expr_msg.expression.c_str(), expr_msg.speech.c_str(), expr_msg.look.c_str());


		expression_command.publish(expr_msg);

		ros::spinOnce();

		loop_rate.sleep();
	}


	return 0;
}

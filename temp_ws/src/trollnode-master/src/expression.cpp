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
#include "trollnode/expression.h"
//#include "trollnode/expression_templates.h"
#define NEUTRAL_INTENSITY 0
#define DEFAULT_START_TIME 0




/*mapping strings look and emotion from ROS modules to templates with actions being sent to the trollface*/
void Expression::addActions(std::string action)
{
	//collection of actions for each expression
	static std::map< std::string, std::vector<actionUnit> > lookup = {
		{ "angry", {{3,0,0,1,1},{4,0,0,1,1},{5,0,0,1,1},{6,0,0,1,1},{7,0,0,1,1},{23,0,0,1,1}} },
		{ "smile", {{12,0,0,1,1}} },
		{ "neutral", {}},
		{ "happy", { {6,0,0,1,1},{12,0,0,1,1},{25,0,0,1,1}} },
		{ "sad", {{1,0,0,1,1},{15,0,0,1,1},{41,0,0,1,1}} },
		{ "surprise", { {1,0,0,1,1},{2,0,0,1,1},{5,0,0,1,1},{26,0,0,1,0.5},{27,0,0,1,0.5}} },
		{ "suspicious", {{9,0,0,1,1},{17,0,0,1,1},{42,0,0,1,1}} },
		{ "disgust", {{4,0,0,1,1},{6,0,0,1,1},{7,0,0,1,1},{90,0,0,1,1},{10,0,0,1,1},{11,0,0,1,1},{23,0,0,1,1},{44,0,0,1,1}} },
		{ "pain", {{4,0,0,1,1},{7,0,0,1,1},{9,0,0,1,1},{10,0,0,1,1},{12,0,0,1,1},{25,0,0,1,1},{26,0,0,1,0.5},{43,0,0,1,1}} },
		{ "right", {{52,0,0,1,0.35}} },
		{ "left", {{51,0,0,1,0.35}} },
		{ "up", {{53,0,0,1,0.35}} },
		{ "down", {{54,0,0,1,0.35}} }
	};

	//setting actions to vector<actionUnit> corresponding to the recieved expression
	if (action.compare("") != 0) {
		auto it = lookup.find(action);
		if (it != lookup.end()) {
			actions.insert(actions.end(), it->second.begin(), it->second.end());
		} else {
			ROS_ERROR("Did not recognize action [%s], current expression not changed.",action.c_str());
			//actions = NULL;
		}
	 }	
}

//void Expression::addEmotion

void Expression::addLookDirection(const estimate_interest::DirectionStatus::ConstPtr& msg)
{
	lookDir = msg->direction;
	emotion = "angry";
	ROS_INFO("GOT DIRECTION %s EMOTION IS %s", lookDir, emotion);
	return;
}

void Expression::addSpeech(const speech_processing::Expression::ConstPtr& msg)
{
	emotion = msg->expression;
	speech = msg->speech;
	return;
}

std::string translateAction(actionUnit action)
{
	static std::map<int, std::string> actionNumberToString {
		{1 ,  "AU01innerbrowraiser"},
		{2 ,  "AU02outerbrowraiser"},
		{201 ,  "AU02outerbrowraiserL"},
		{202 ,  "AU02outerbrowraiserR"},
		{3 ,  "AU03procerus"},
		{4 ,  "AU04browlowerer"},
		{5 ,  "AU05upperlidraiser"},
		{6 ,  "AU06cheekraiser"},
		{7 ,  "AU07lidtightener"},
		{8 ,  "AU08liptowardeachother"},
		{9 ,  "AU09nosewrinkler"},
		{10 ,  "AU10upperlipraiser"},
		{11 ,  "AU11nasolabialfurrowdeepener"},
		{12 ,  "AU12lipcornerpuller"},
		{1201 ,  "AU12lipcornerpullerL"},
		{1202 ,  "AU12lipcornerpullerR"},
		{13 ,  "AU13cheekpuffer"},
		{14 ,  "AU14dimpler"},
		{15 ,  "AU15lipcornerdepressor"},
		{16 ,  "AU16lowerlipdepressor"},
		{17 ,  "AU17chinraiser"},
		{18 ,  "AU18lippuckerer"},
		{19 ,  "AU19tongueshow"},
		{20 ,  "AU20lipstretcher"},
		{21 ,  "AU21necktightener"},
		{22 ,  "AU22lipfunneler"},
		{23 ,  "AU23liptightener"},
		{24 ,  "AU24lippressor"},
		{25 ,  "AU25lipspart"},
		{26 ,  "AU26jawopen"},
		{27 ,  "AU27mouthstretch"},
		{28 ,  "AU28lipsuck"},
		{29 ,  "AU29jawthrust"},
		{2901 ,  "AU29jawthrustN"},
		{30 ,  "AU30jawsidewaysL"},
		{3001 ,  "AU30jawsidewaysR"},
		{31 ,  "AU31jawclencher"},
		{32 ,  "AU32bite"},
		{33 ,  "AU33blow"},
		{34 ,  "AU34puff"},
		{35 ,  "AU35cheeksuck"},
		{36 ,  "AU36tonguebuldgeL"},
		{3601 ,  "AU36tonguebuldgeR"},
		{37 ,  "AU37lipwipeL"},
		{3701 ,  "AU37lipwipeM"},
		{3702 ,  "AU37lipwipeR"},
		{38 ,  "AU38nostrildilate"},
		{39 ,  "AU39nostrilcompress"},
		{40 ,  ""},
		{41 ,  "AU41liddrop"},
		{42 ,  "AU42slit"},
		{43 ,  "AU43eyesclosed"},
		{44 ,  "AU44squint"},
		{45 ,  "AU45blink"},
		{4501 ,  "AU45blink_50"},
		{46 ,  "AU46winkR"},
		{47 ,  "AU47winkL"},
		{51 ,  "AU51turnleft"},
		{52 ,  "AU52turnright"},
		{53 ,  "AU53headup"},
		{54 ,  "AU54headdown"},
		{55 ,  "AU55tiltleft"},
		{56 ,  "AU56tiltright"},
		{57 ,  "AU57headforward"},
		{58 ,  "AU58headback"},
		{66 ,  "AU66crosseye"}
		};

	auto it = actionNumberToString.find(action.AU);
	if (it != actionNumberToString.end()) {
		return it->second;      //","<<STOP_TIME<<","<<action.stopIntensity;

	} else {
		ROS_ERROR("Did not recognize action [%i], current action not added",action.AU);
		return "";
	}
}

void Expression::relaxExpression(Expression previous)
{
	bool found;
	for (int i=0; i < previous.actions.size();i++)
	{
		found=false;
		for (int j=0; j<this->actions.size();j++)
		{
			/*if the same action is used by following expressions, change new startIntensity to 
			current intensity*/
			if(this->actions[j].AU==previous.actions[i].AU)
			{
				this->actions[j].startIntensity = previous.actions[i].stopIntensity;
				found=true;
				break;
			}
		/*if a previous action has not ended with neutral_intensity, 
		add relaxing action to new expression */
		}
		if(previous.actions[i].stopIntensity!=NEUTRAL_INTENSITY && !found)
				this->actions.push_back({previous.actions[i].AU, previous.actions[i].startTime,
				previous.actions[i].stopIntensity, previous.actions[i].stopTime, NEUTRAL_INTENSITY});
	}
}

std::string Expression::translateToString()
{
	std::stringstream stringToSend;
	//std::string temp;
	if(0<actions.size())
	{
		/*translate all actions in expression to string accepted by trollface*/
		for(int i=0;i<actions.size();i++)
		{

			stringToSend << "[" << translateAction(actions[i]) << "," << actions[i].startTime << ","
			<< actions[i].startIntensity << "," << actions[i].stopTime << "," <<actions[i].stopIntensity << "]";
		}
		//adds speech at the end of string
		stringToSend << speech;
		return stringToSend.str();
	}
	else
		ROS_INFO("No actions in expression found");
		return "";
}

std::string Expression::createExpression(Expression previous)
{
	//addLookDirection();
	//addSpeech();
	addActions(lookDir);
	addActions(emotion);
	relaxExpression(previous);
	return translateToString();

}

void Expression::sendString(const ros::TimerEvent& timer)
{


	return;
}
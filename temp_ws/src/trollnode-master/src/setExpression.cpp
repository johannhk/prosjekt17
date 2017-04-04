/**
	Node for receiving facial expression commands, creating BL_readable messages and sending them
	over TCP to the Trollserver.


	Subscribes to:
		- trollExpression

*/


//ROS
#include "ros/ros.h"
#include <ros/callback_queue.h>

//Misc
#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <vector>


//Sockets
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 


//ROS message files
#include <trollnode/Expression.h>
#include "std_msgs/String.h"

//Other includes
#include "trollnode/expression_templates.h" //File that contains the premade troll expressions

// NETWORK DETAILS
#define EXPRESSION_PORT		"8888" //Port used to send expression messages to the Trollserver
#define DEFAULT_ADDRESS 	"192.168.1.40" 
int socket_id;

//Other defines
#define NEUTRAL_INTENSITY 	0 //Intensity value of an action unit when relaxed/inactive/neutral.
#define EXPRESSION_TIME 	1 //Time in seconds the Troll should use to transition between facial expressions

//Namespace

//Ros topic names
std::string troll_expression_topic_name = "trollExpression"; //Topic for getting commands for the troll. Speech, looking direction and facial expressions.

//directions for eye movement
enum class Direction {
	Up,
	Down,
	Left,
	Right,
	Neutral
};


//Pointers to current and earlier expressions
actionUnit *currentExpression = neutral;  //Pointer to the current array containing the current expression
actionUnit *lookingExpression = neutral; 	//Direction the troll should look in.
actionUnit *previousLookingExpression = neutral; 

std::vector<actionUnit> lastExpression; //Vector that stores actionUnit structs that was used in the previous expression




// maps AU number to their text code. when there are multiple strings sharing one number, the number is multiplied by 100 and one is added for each duplicate (02 becomes 201, 202, etc).
std::string getAUName(int AU)
{
	static std::map< int, std::string > autostring {
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
	{66 ,  "AU66crosseye"}, };
	auto it = autostring.find(AU);
		if (it != autostring.end()){
			return it->second;
		}
		return "";
}




// Function for setting the current expression pointer at the right expression container
actionUnit* set_current_expression(const std::string & expression)
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
}


//int set_looking_direction(const std::string & direction)
actionUnit * set_looking_direction(Direction dir)
{
	switch (dir) {
	case Direction::Up:      return up;
	case Direction::Down:    return down;
	case Direction::Left:    return left;
	case Direction::Right:   return right;
	case Direction::Neutral: return neutral;
	}
}

// Function returns a string for activating an Action unit on the trollface.
std::string createAUString(int AU, float startIntensity, float stopIntensity, float stopTime)
{
	std::stringstream AUString;
	
	AUString << "[" << getAUName(AU) << ",0," << startIntensity << "," << stopTime << "," << stopIntensity << "]";
	
	return AUString.str();
	
}

//connects to trollserver
int connectToServer(const char* ip_address, const char* port_number)
{
	struct addrinfo hints, *res;
	int status, socket_id;
	//
	memset(&hints, 0, sizeof (hints));
	hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	
	//get address info of ip_address, fill up linked list of res
	status = getaddrinfo(ip_address, port_number, &hints, &res);
	if(status != 0) {
        ROS_INFO("Error getaddrinfo: [%s]:", strerror(errno));
        exit(1);
    }   
    
    //get file descriptor(handle to input/output resource)
    socket_id = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(socket_id < 0) {
        ROS_INFO("Error socket %s", strerror(errno));
        exit(2);
    }
    //connect socket_id to address
    status = connect(socket_id, res->ai_addr, res->ai_addrlen);
    if(status < 0) {
        ROS_INFO("Error connect %s", strerror(errno));
        exit(3);
    }
    ROS_INFO("CONNECTED TO TCPSERVER");
    return socket_id;
}




// Creates a BL readable message containing the received expression and speech, and sends it over TCP to the Trollserver.
void sendMsg( const trollnode::Expression::ConstPtr& msg, int socket_id)
{
	std::string msgString;
	
	float expressionTime = EXPRESSION_TIME; //transition time from one expression to the next. 
	int currentExprSize = 0;
	int lookingExpressionSize = 0;
	

	//Setting pointers to the new expression/direction
	currentExpression=set_current_expression(msg->expression);
	lookingExpression=set_looking_direction(Direction::Up);

	int k = 0;
	bool foundDuplicateAU;
	
	while(currentExpression[k].AU != 0)
	{
		currentExprSize++;

		for(int i = 0; i < lastExpression.size(); i++)
		{
			
	
			foundDuplicateAU = false;
		
			//handles transition from one intensity to another when an AU is used by both expressions
			if(currentExpression[k].AU == lastExpression[i].AU)
			{
				
				if(currentExpression[k].intensity != lastExpression[i].intensity)
				{
					msgString.append(createAUString(currentExpression[k].AU, lastExpression[i].intensity,
					currentExpression[k].intensity,expressionTime));
					

				}
				lastExpression.erase(lastExpression.begin() + i); 
				foundDuplicateAU = true;
				break;
			}
			
		}
		
		//appends string for activating relaxed AU for the new expression
		if(!(foundDuplicateAU ))
		{
			msgString.append(createAUString(currentExpression[k].AU, NEUTRAL_INTENSITY,
			currentExpression[k].intensity,expressionTime));
		}
		
		k++;
	}

	//handle looking direction
	if(lookingExpression[0].AU != previousLookingExpression[0].AU)
	{

		//relax old AU if it it's not neutral
		if(previousLookingExpression[0].AU != 0)
		{
			msgString.append(createAUString(previousLookingExpression[0].AU, previousLookingExpression[0].intensity,
			NEUTRAL_INTENSITY,expressionTime));
		}
		// Activate new AU
		msgString.append(createAUString(lookingExpression[0].AU, NEUTRAL_INTENSITY,
			lookingExpression[0].intensity,expressionTime));

		previousLookingExpression = lookingExpression;
	}


	
	
	//appends messages for relaxing the AU from the previous expression
	for(int i = 0; i < lastExpression.size();i++)
	{
		msgString.append(createAUString(lastExpression[i].AU, lastExpression[i].intensity,
		NEUTRAL_INTENSITY,expressionTime));
		
	}
	
	lastExpression.assign(currentExpression,currentExpression + currentExprSize); //updates vector of last expressions

	// insert speech at the end of the BL message
	msgString.append(msg->speech.c_str());
	std::cout<<msgString<<'\n';
	
	
	// Sending the BL message over TCP
	if ( send(socket_id,msgString.c_str(),strlen(msgString.c_str()), 0 ) < 0)
	{
		
		ROS_ERROR("ERROR writing to socket, errorno: [%s]", strerror(errno));
	    close(socket_id);
	}
	else
		ROS_INFO("Message succesfully sent");
	
}



//Callback function for trollExpression topic. Sets up the TCP connection to the Trollserver
void expressionHandler(const trollnode::Expression::ConstPtr& msg)
{
	
	ROS_INFO("Received Expression: [%s], speech: [%s], Direction: [%s]", msg->expression.c_str(), msg->speech.c_str(), msg->look.c_str());
	
	if(errno == ECONNRESET || errno == ETIMEDOUT || errno == EPIPE )
		return;

	sendMsg(msg, socket_id);
}


int main(int argc, char *argv[])
{
	//set up connection to trollserver

	socket_id=connectToServer(DEFAULT_ADDRESS, EXPRESSION_PORT);


	    
    const char* msg="hello\0";
    send(socket_id, msg, strlen(msg), 0);
   

    ROS_INFO("CONNECTED TO TCPSERVER");
	ros::init(argc, argv, "setExpression");
	ros::NodeHandle n;

	//Subscriber
	ros::Subscriber expression  = n.subscribe(troll_expression_topic_name,3,expressionHandler);

	ros::spin();
	
	return 0;

}

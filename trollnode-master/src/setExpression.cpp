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
#define EXPRESSION_PORT		8888 //Port used to send expression messages to the Trollserver

//IP adress of Trollserver
#define DEFAULT_ADDRESS 	"129.241.154.37" 

//Other defines
#define NEUTRAL_INTENSITY 	0 //Intensity value of an action unit when relaxed/inactive/neutral.
#define EXPRESSION_TIME 	1 //Time in seconds the Troll should use to transition between facial expressions

//Namespace

//Ros topic names
std::string troll_expression_topic_name = "trollExpression"; //Topic for getting commands for the troll. Speech, looking direction and facial expressions.




// TCP variables for expressions
int 				exprSocket, exprPortNo;
bool 				exprTCPInit = false;
struct sockaddr_in 	exprServerAddr;
struct hostent 		*exprServer;




//Pointers to current and earlier expressions
actionUnit *currentExpression = neutral;  //Pointer to the current array containing the current expression
actionUnit *lookingExpression = neutral; 	//Direction the troll should look in.
actionUnit *previousLookingExpression = neutral; 

std::vector<actionUnit> lastExpression; //Vector that stores actionUnit structs that was used in the previous expression




// Translates AU number into their text code. when there are multiple strings sharing one number, the number is multiplied by 100 and one is added for each duplicate (02 becomes 201, 202, etc).
std::string getAUName(int AU)
{
	switch(AU)
	{
		case 1: return "AU01innerbrowraiser";
			break;
		case 2: return "AU02outerbrowraiser";
			break;
		case 201: return "AU02outerbrowraiserL"; //multiple versions exist for this AU
			break;
		case 202: return "AU02outerbrowraiserR"; //multiple versions exist for this AU
			break;
		case 3: return "AU03procerus";
			break;
		case 4: return "AU04browlowerer";
			break;
		case 5: return "AU05upperlidraiser";
			break;
		case 6: return "AU06cheekraiser";
			break;
		case 7: return "AU07lidtightener";
			break;
		case 8: return "AU08liptowardeachother";
			break;
		case 9: return "AU09nosewrinkler";
			break;
		case 10: return "AU10upperlipraiser";
			break;
		case 11: return "AU11nasolabialfurrowdeepener";
			break;
		case 12: return "AU12lipcornerpuller"; //multiple versions exist for this AU
			break;
		case 1201: return "AU12lipcornerpullerL"; //multiple versions exist for this AU
			break;
		case 1202: return "AU12lipcornerpullerR"; //multiple versions exist for this AU
			break;
		case 13: return "AU13cheekpuffer";
			break;
		case 14: return "AU14dimpler";
			break;
		case 15: return "AU15lipcornerdepressor";
			break;
		case 16: return "AU16lowerlipdepressor";
			break;
		case 17: return "AU17chinraiser";
			break;
		case 18: return "AU18lippuckerer";
			break;
		case 19: return "AU19tongueshow";
			break;
		case 20: return "AU20lipstretcher";
			break;
		case 21: return "AU21necktightener";
			break;
		case 22: return "AU22lipfunneler";
			break;
		case 23: return "AU23liptightener";
			break;
		case 24: return "AU24lippressor";
			break;
		case 25: return "AU25lipspart";
			break;
		case 26: return "AU26jawopen";
			break;
		case 27: return "AU27mouthstretch";
			break;
		case 28: return "AU28lipsuck";
			break;
		case 29: return "AU29jawthrust"; //multiple versions exist for this AU
			break;
		case 2901: return "AU29jawthrustN"; //multiple versions exist for this AU
			break;
		case 30: return "AU30jawsidewaysL"; //multiple versions exist for this AU
			break;
		case 3001: return "AU30jawsidewaysR"; //multiple versions exist for this AU
			break;
		case 31: return "AU31jawclencher";
			break;
		case 32: return "AU32bite";
			break;
		case 33: return "AU33blow";
			break;
		case 34: return "AU34puff";
			break;
		case 35: return "AU35cheeksuck";
			break;
		case 36: return "AU36tonguebuldgeL";  //multiple versions exist for this AU
			break;
		case 3601: return "AU36tonguebuldgeR";  //multiple versions exist for this AU
			break;
		case 37: return "AU37lipwipeL";
			break;
		case 3701: return "AU37lipwipeM"; //multiple versions exist for this AU
			break;
		case 3702: return "AU37lipwipeR"; //multiple versions exist for this AU
			break;
		case 38: return "AU38nostrildilate"; //multiple versions exist for this AU
			break;
		case 39: return "AU39nostrilcompress";
			break;
		case 40: return "";
			break;
		case 41: return "AU41liddrop";
			break;
		case 42: return "AU42slit";
			break;
		case 43: return "AU43eyesclosed";
			break;
		case 44: return "AU44squint";
			break;
		case 45: return "AU45blink";  //multiple versions exist for this AU
			break;
		case 4501: return "AU45blink_50";  //multiple versions exist for this AU
			break;
		case 46: return "AU46winkR";
			break;
		case 47: return "AU47winkL";
			break;
		case 51: return "AU51turnleft";
			break;
		case 52: return "AU52turnright";
			break;
		case 53: return "AU53headup";
			break;
		case 54: return "AU54headdown";
			break;
		case 55: return "AU55tiltleft";
			break;
		case 56: return "AU56tiltright";
			break;
		case 57: return "AU57headforward";
			break;
		case 58: return "AU58headback";
			break;
		case 66: return "AU66crosseye";
			break;
		default: return "";
			break;
	}
}


// Function for setting the current expression pointer at the right expression container
int setCurrentExpression(const std::string & expression)
{
	if (expression.compare("angry") == 0)
	{
		currentExpression = angry;
	}
	else if (expression.compare("smile") == 0)
	{
		currentExpression = smile;
	}
	else if (expression.compare("neutral") == 0)
	{
		currentExpression = neutral;
	}
	else if (expression.compare("happy") == 0)
	{
		currentExpression = happy;
	}
	else if (expression.compare("sad") == 0)
	{
		currentExpression = sad;
	}
	else if (expression.compare("surprise") == 0)
	{
		currentExpression = surprise;
	}
	else if (expression.compare("suspicious") == 0)
	{
		currentExpression = suspicious;
	}
	else if (expression.compare("disgust") == 0)
	{
		currentExpression = disgust;
	}
	else if (expression.compare("fear") == 0)
	{
		currentExpression = fear;
	}
	else if (expression.compare("duckface") == 0)
	{
		currentExpression = duckface;
	}
	else if (expression.compare("pain") == 0)
	{
		currentExpression = pain;
	}
	else if (expression.compare("") == 0)
	{
		//blank expression, keep current expression.
	}
	else //No recognized expression
	{
		ROS_ERROR("Did not recognize expression [%s], current expression not changed.",expression.c_str());
		return -1;
	}
	
	return 0;
}



int set_look_at_direction(const std::string & direction)
{
	if (direction.compare("up") == 0)
	{
		lookingExpression = up;
	}
	else if (direction.compare("down") == 0)
	{
		lookingExpression = down;
	}
	else if (direction.compare("left") == 0)
	{
		lookingExpression = left;
	}
	else if (direction.compare("right") == 0)
	{
		lookingExpression = right;
	}
	else if (direction.compare("neutral") == 0)
	{
		lookingExpression = neutral;
	}
	else
		return -1;

	return 0;

}

// Function returns a string for activating an Action unit on the trollface.
std::string createAUString(int AU, float startIntensity, float stopIntensity, float stopTime)
{
	std::stringstream AUString;
	
	AUString << "[" << getAUName(AU) << ",0," << startIntensity << "," << stopTime << "," << stopIntensity << "]";
	
	return AUString.str();
	
}





// Creates a BL readable message containing the received expression and speech, and sends it over TCP to the Trollserver.
void sendMsg( const trollnode::Expression::ConstPtr& msg)
{
	std::string msgString;
	
	float expressionTime = EXPRESSION_TIME; //transition time from one expression to the next. 
	int currentExprSize = 0;
	int lookingExpressionSize = 0;
	

	//Setting pointers to the new expression/direction
	setCurrentExpression(msg->expression); 
	set_look_at_direction(msg->look);
	

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
	
	
	// Sending the BL message over TCP
	if ( send(exprSocket,msgString.c_str(),strlen(msgString.c_str()), 0 ) < 0)
	{
		
		ROS_ERROR("ERROR writing to socket, errorno: [%s]", strerror(errno));
	    close(exprSocket);
	    exprTCPInit = false;
	}
	else
		ROS_INFO("Message succesfully sent");
	
}



//Callback function for trollExpression topic. Sets up the TCP connection to the Trollserver
void expressionHandler(const trollnode::Expression::ConstPtr& msg)
{
	
	ROS_INFO("Received Expression: [%s], speech: [%s], Direction: [%s]", msg->expression.c_str(), msg->speech.c_str(), msg->look.c_str());
	
	if ( errno == ECONNRESET || errno == ETIMEDOUT || errno == EPIPE )
	{

		ROS_INFO("Initializing TCP, errorno: [%s]", strerror(errno));
		errno = 0;

		//Setting up sockets and client
		exprPortNo = EXPRESSION_PORT;
		exprSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (exprSocket < 0)
			ROS_ERROR("ERROR opening socket");

		exprServer = gethostbyname(DEFAULT_ADDRESS);

		if (exprServer == NULL) 
		{
			ROS_ERROR("ERROR, no such host\n");
			exit(0);
		}

		bzero((char *) &exprServerAddr, sizeof(exprServerAddr));

		exprServerAddr.sin_family = AF_INET;
		exprServerAddr.sin_port = htons(exprPortNo);


		bcopy((char *)exprServer->h_addr, (char *)&exprServerAddr.sin_addr.s_addr, exprServer->h_length);



		//Connecting to Trollserver
		if (connect(exprSocket,(struct sockaddr *) &exprServerAddr,sizeof(exprServerAddr)) < 0)
		{
			ROS_ERROR("ERROR connecting");
			close(exprSocket);
			exprTCPInit = false;
		}
		else
		{
			exprTCPInit = true;
			ROS_INFO("Created connection to Trollserver");
		}
	}
	
	if(exprTCPInit)
	{
		sendMsg(msg);
	}
	else
		ROS_INFO("TCP connection not established, message disregarded");
}






int main(int argc, char *argv[])
{

	ros::init(argc, argv, "setExpression");
	ros::NodeHandle n;

	//Subscriber
	ros::Subscriber expression  = n.subscribe(troll_expression_topic_name,3,expressionHandler);

	ros::spin();
	
	return 0;

}

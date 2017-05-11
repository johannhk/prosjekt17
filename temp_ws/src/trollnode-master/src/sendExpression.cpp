//ROS specific
#include "ros/ros.h"
#include <ros/callback_queue.h>
#include <ros/time.h>

//custom header- and messagefiles from ROS

#include "trollnode/expression.h"


//sockets/misc
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 


//IP4 address and port for the trollface TCP server
#define IP_ADDRESS 	"10.0.2.15"
#define PORT 		"8888"

//connects to trollserver via TCP
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

void sendString(int socket_id, std::string msgString)
{
	//add check if still up
	send(socket_id, msgString.c_str(), msgString.size(), 0);
}


int main(int argc, char **argv)
{



	int socket_id = connectToServer(IP_ADDRESS, PORT);
	
	ros::init(argc, argv, "setExpression");
	ros::NodeHandle n;

	Expression current;
	Expression previous;

	//rate set in hz
	ros::Rate sending_rate (0.2);
	std::string msgString;
	while(ros::ok())
	{
		ROS_INFO("Sleep");
		sending_rate.sleep();
		ROS_INFO("!ASD!");
		//msgString = current.createExpression(previous);
		//sendString(socket_id, msgString);
		ros::spinOnce();
		sending_rate.sleep();	}

	//subscribes to publishExpression and adds to queue
	//ros::Subscriber setExpression = n.subscribe("expression_topic", 100, &ExprQueue::addExpression, &queue);
	
	//Send expression over TCP

}
#include "ros/ros.h"
#include <ros/callback_queue.h>

//rest
#include <sstream>

//headerfiles and messagefiles relevant for this package
#include "std_msgs/String.h"
#include "trollnode/Expression.h"
#include "trollnode/expression_class.h"
//#include "trollnode/expression_templates.h"
//sockets
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

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


void ExprQueue::addExpression(const trollnode::Expression::ConstPtr& msg)
{
	ROS_INFO("got message %s", msg->speech.c_str());
	//send()


}

int main(int argc, char **argv)
{

	int socket_id=connectToServer(IP_ADDRESS, PORT);
	ros::init(argc, argv, "setExpression");
	ros::NodeHandle n;


	//subscribes to publishExpression and adds to queue
	ExprQueue queue;
	ros::Subscriber setExpression = n.subscribe("expression_topic", 100, &ExprQueue::addExpression, &queue);

	ros::spin();
	

}
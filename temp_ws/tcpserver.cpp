//tcp.server - general
#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
//#include <string>

//
#define PORTNUMBER "8888"
#define IPADDRESS "129.241.154.72"



void tcp_init_server(const char* ip_address, char* port_number)
{
  struct addrinfo hints, *socket_list;
  struct sockaddr_storage their_addr;
  socklen_t addr_size;
  int status, sockfd, new_sockfd;



  memset(&hints, 0, sizeof( hints ));
  hints.ai_family=AF_UNSPEC; //dont vare whether IPv4 or 6
  hints.ai_socktype = SOCK_STREAM; //TCP streaming socket
  hints.ai_protocol = 0; //socket address with any protocol can be returned
  //hints.ai_flags=AI_PASSIVE; //fills in ip if ip_adress=null and uncommented
  

  //load up adress structs with getaddrinfo in socket_list, list because for several IPs of name it creates a linked list
  if ((status = getaddrinfo(ip_address, port_number, &hints, &socket_list)) != 0) {
      fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
      exit(1);
  }

  //creates a socket descripter with the arguments from socket_list in getaddrinfo
  sockfd=socket(socket_list->ai_family, socket_list->ai_socktype, socket_list->ai_protocol);
  //bind socket descriptor and listen with up to 10 connnections
  bind(sockfd, socket_list->ai_addr, socket_list->ai_addrlen);
  if ((status=listen(sockfd, 10))!=0) {
      fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
      exit(1);
  }

  addr_size = sizeof their_addr;
  new_sockfd=accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
  std::string buf;
  int len;
  recv(new_sockfd, buf, len, 0);
  //CODE GOES HERE

  freeaddrinfo(socket_list);
}

void tcp_init_client()
{


}

int main()
{
  tcp_init_server(IPADDRESS, PORTNUMBER);

  return 0;

}
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define SERV_TCP_PORT 8000 /* server's port number */
#define MAX_SIZE 80

int main(int argc, char *argv[])
{
  int sockfd, newsockfd, clilen;
  struct sockaddr_in cli_addr, serv_addr;
  int port;
  char string[MAX_SIZE];
  int len;
  
  /* command line: server [port_number] */
  
  if(argc == 2) 
     sscanf(argv[1], "%d", &port); /* read the port number if provided */
  else
     port = SERV_TCP_PORT;
  
  /* open a TCP socket (an Internet stream socket) */
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
     perror("can't open stream socket");
     exit(1);
  }
  	
  /* bind the local address, so that the cliend can send to server */
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(port);
  
  if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
     perror("can't bind local address");
     exit(1);
  }
	
  /* listen to the socket */
  listen(sockfd, 5);

  for(;;) {

     /* wait for a connection from a client; this is an iterative server */
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		
     if(newsockfd < 0) {
        perror("can't bind local address");
     }
   
     /* read a message from the client */
     len = read(newsockfd, string, MAX_SIZE); 
     /* make sure it's a proper string */
     string[len] = 0;
     printf("%s\n", string);
     
     close(newsockfd);
  }  
}


#include<string.h>
#include<sys/types.h>          
#include <sys/socket.h>
#include<stdlib.h>
#include<strings.h>
#include<stdio.h>
#include<netinet/tcp.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#define SERV_TCP_PORT 9000
#define MAX_SIZE 100  

// int socket(int domain, int type, int protocol);
//int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
//int listen(int sockfd, int backlog);
//int accept4(int sockfd, struct sockaddr *addr,socklen_t *addrlen, int flags);
// int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
//int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
//ssize_t recv(int sockfd, void *buf, size_t len, int flags);
//int strcmp(const char *s1, const char *s2);
//int strncmp(const char *s1, const char *s2, size_t n);

int main()
{
  int sockfd,cl_sockfd,clilen;
  struct sockaddr_in serv_addr;
  int port,len;
  char str[MAX_SIZE];
  //open a socket stream
  if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
  {
  perror("can''t open stream socket\n");
  exit(1);
  }
  //initialize sockaddr in structure
  bzero((char*)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = 9000;
  //connect to server
  if(connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
  {
  perror("can't connect stream socket\n");
  exit(1);
  }
 //Communicate via system calls
  while(1)
  {
  printf("Client: ");
  fgets(str,100,stdin);
  len = send(sockfd,str,100,0);
  if(strncmp(str,"end",3)==0)
 {
  break;
 }
  len =recv(sockfd,str,100,0);
  printf("Server : %s ",str);
}
  close(sockfd);
  return 0;
 }


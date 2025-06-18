#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERV_TCP_PORT 9000
#define MAX_SIZE 100
int main(){
    int sockfd, cl_sockfd, clilen;
    struct sockaddr_in cli_addr, serv_addr;
    int port, len;
    char str[MAX_SIZE];
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
           perror("can't open stream socket.\n");
           exit(1);
    }   
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = 9000; 
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0) {
           perror("can't bind stream socket.\n");
           exit(1);
    }    
    listen(sockfd,5);    
    clilen = sizeof(cli_addr);
    cl_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);   
    while(1){
        len = recv(cl_sockfd, str, 100, 0);
        printf("Client: %s",str);     
        if(strncmp(str, "end" , 3) == 0){
            break;
        }        
        printf("\nServer: ");
        fgets(str, 100, stdin);        
        len = send(cl_sockfd, str, 100, 0);  
    }
    printf("Client Requested Termination.. \n");
    
    close(cl_sockfd);
    
    return 0;  
    
 }  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

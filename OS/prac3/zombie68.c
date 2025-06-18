#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

 int main (void){
 int pid;
 pid = fork();
 if(pid != 0){
 printf("Shh.. Main is sleeping. \n ");
 
 while(1){
 sleep(1000);
 }}
 
 else{
 printf("In child()...\n");
 exit(42);
 }
 printf("In main..\n");
 return 0;
 
 }

#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(){
pid_t p;
int status;
p = fork();
if(p==0){
printf("CHILD PROCESS....\n");
exit(0);
}
else if(p>0){
printf("\t PARENT PROCESS...\n");
wait(&status);
printf("\t PARENT WAITING....\n");
if(WIFEXITED(status)){
printf("\n\t CHILD TERMINATED: %d\n", WEXITSTATUS(status));
}
printf("PARENT TERMINATES...\n");
}
else if(p == -1){
printf("\n FAILED: Unsuccessful fork()\n");
}
return 0;
}

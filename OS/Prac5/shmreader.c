#include <string.h> 
#include<stdio.h>
#include <stdlib.h> 
#include <sys/shm.h> 
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h>

int main(){
int i, shmid, len, num, slen, temp;
void *sharedMem;
char buff[100], str[100] = {0};

shmid = shmget ((key_t) 12345, 1024, 0666); //ftok() 
printf("Reader: SHMID := %d\n", shmid);

sharedMem = shmat (shmid, NULL, 0);

printf("Reader: Process attached at %p\n", sharedMem);
printf("Data read: %s\n", (char *) sharedMem);

strcpy(str, sharedMem);
slen = strlen(str);

for(i=0;i< slen / 2;i++) { 
temp = str[i];
str[i]= str[slen - i - 1];
str[slen- i - 1] = temp;
}
printf("Reveresed number is :%s\n",str);
shmdt (sharedMem);

/*
shmctl System V shared memory control
#include <sys/ipc.h>
#include <sys/shm.h>
int shmctl(int shmid, int cmd, struct shmid ds *buf);
*/

shmctl (shmid, IPC_RMID, NULL);
return 0;
}

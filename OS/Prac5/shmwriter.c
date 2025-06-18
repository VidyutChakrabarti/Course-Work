#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/shm.h> 
#include <sys/types.h> 
#include <unistd.h>

int main(){
int i;
void *sharedMem;
int shmid;

/**
shmget allocates a System V shared memory segment
#include <sys/ipc.h>
#include <sys/shm.h>
int shmget (key_t key, size_t size, int shmflg);
**/

shmid = shmget ((key_t) 12345, 1024, 0666 | IPC_CREAT); 
printf("Writer: SHMID := %d\n", shmid);
/**
#include <sys/types.h>
#include <sys/shm.h>
void *shmat (int shmid, const void *shmaddr, int shmflg); int shmdt (const void *shmaddr);
**/
sharedMem = shmat (shmid, NULL, 0);
printf("Writer: Process attached at %p\n", sharedMem);
printf("Enter data: \n");
read(0,sharedMem, 100);
printf("\nNumber Written to Shared Memory..\n"); 
//shmdt (sharedMem);
return 0;
}

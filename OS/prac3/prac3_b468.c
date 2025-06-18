#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(){
   int s, pid;
printf("Enter 1 for creating processes that execute the address space of the parent\nEnter 2 for executing process that does not execute the address space of the parent process\nEnter 3 for displaying IDs of parent and child processes.\nEnter 4 for executing execl.\nEnter 5 for executing execlp\nEnter 6 for executing execle\nEnter 7 for executing execv\nEnter 8 for executing execvp\nEnter 9 for executing execvpe\nEnter 10 for creating zombie process.\nEnter 11 for creating an orphan process.\nEnter 12 to list plausible orphan processes.\n");
  printf("Enter your choice: ");
  scanf("%d", &s);

  switch(s){

/** [1] Create processes that execute the address space of the parent. **/
    case 1:
      printf("Executing Fork...\n");
      pid = fork();
      if(pid==0){
      printf("Child created successfully.\n");
      printf("pid of child: %d\n", getpid());
      printf("parent(pid): %d\n", getppid());
      printf("Hello, I am the child executing...\n");
      } 
      else{
      printf("parent continues... \n");
      printf("grandparent(pid): %d\n", getppid());
      printf("pid of parent: %d\n", getpid());
      printf("Hello, this is the parent executing...\n");
      }
      printf("TERMINATING\n");
      printf("=============================================================\n");
      break;
    case 2:
      printf("VFork execution...\n");
      pid = vfork();
      if(pid==0){
      printf("Child created successfully.\n");
      printf("pid of child: %d\n", getpid());
      printf("parent(pid): %d\n", getppid());
      printf("Child executing.\n");
      sleep(5);
      }
      else{
      printf("Parent continues... \n");
      printf("grandparent(pid): %d\n", getppid());
      printf("pid of parent: %d\n", getpid());
      printf("Parent executing.\n");
      }
      printf("TERMINATING\n"); 
      printf("=============================================================\n");
      break;
    case 3:
      printf("Executing Fork...\n");
      pid = fork();
      if(pid==0){
      printf("Child created successfully.\n");
      printf("pid of child: %d\n", getpid());
      printf("parent(pid): %d\n", getppid());
      printf("Hello, I am the child executing...\n");
      } 
      else{
      printf("parent continues... \n");
      printf("grandparent(pid): %d\n", getppid());
      printf("pid of parent: %d\n", getpid());
      printf("Hello, this is the parent executing...\n");
      }
      printf("TERMINATING\n");
      printf("=============================================================\n");
      break;
    case 4:
      printf("EXECUTING EXECL:\n");
      const char *path = "/usr/bin/ls";
      const char *arg2 = "-l";
      const char *arg3 = "prac3_b468.c";
      printf("Finding prac3_b468.c in directory: \n");
      execl(path, path, arg2 , arg3 ,NULL);
      //arg1 : Path, every argument list must be terminated by NULL. 
      // beacuse we have overwritten this address space with execl. thereforE the next line doesn't execute.... 
      printf("\nTask over..........");
      printf("=============================================================\n");
      break;
    case 5:
      printf("EXECUTING EXECLP:\n");
      const char *file = "ls"; // only filename no path, execlp will search for path automatically.
      const char *a2 = "-l";
      const char *a3 = "prac3_b468.c";
      printf("Finding prac3_b468.c in directory: \n");
      execlp(file, file, a2 , a3 ,NULL); 
      printf("\nTask over..........");
      printf("=============================================================\n");
      break;
    case 6:
      // which bash
      //echo $PATH
      printf("EXECLE EXECUTION:\n");
      const char *pathname = "/usr/bin/bash"; // we need to exeute inside shell
      const char *ag2 = "echo $ENV1 $ENV2!"; // initializing the enivronment variables 
      const char *envp[] = {"ENV1=HELLO","ENV2=WORLD! THIS IS VIDYUT",NULL}; // setting the env variables
      execle(pathname,pathname,"-c",ag2,NULL,envp); //-c flag needed for bash
      printf("\nTask over..........");
      printf("=============================================================\n");
      break;
    case 7:
      printf("EXECV EXECUTION: \n");
      const char *pn = "/usr/bin/ls"; 
      printf("Listing prac3_b468.c via execv: \n");
      char *const args[] = {"/usr/bin/ls","-l","prac3_b468.c",NULL};//using array for execv
      execv(pn ,args);
      printf("\nTask over..........");
      printf("=============================================================\n");
      break;
    case 8:
      printf("EXECVP EXECUTION:\n");
      const char *filename = "ls"; 
      char *const arguments[] = {"ls","-l","prac3_b468.c",NULL};
      printf("Listing prac3_b468.c via execvp: \n");
      execvp(filename,arguments);
      printf("\nTask over..........");
      printf("=============================================================\n");
      break;
    case 9:
      printf("EXECVPE DEMO :\n");
      const char *fn = "/bin/bash"; 
      const char *ar[] = {"echo $ENVP1 $ENVP2",NULL}; 
      const char *envpe[] = {"ENVP1=HELLO","ENVP2=WORLD! I AM B4_68.",NULL}; 
      execvpe(fn,fn,"-c",ar,envpe); 
      printf("\nTask over..........\n");
      printf("=============================================================\n");
      break;
    case 10:
      printf("Creating a zombie process in the background by executing zombie.c.\n");
      system("gcc zombie68.c -o ./zombie.out");
      printf("Initiating zombie...\n");
      system("./zombie.out &");
      break;
    case 11:
      printf("Executing an orphan process by running orphanb4_68.c...\n ");
      system("gcc orphanb4_68.c -o orphan.out");
      system("./orphan.out");
      printf("==================================================================\n");
      break;
    case 12:
      printf("Checking for orphan processes..\n");
      system("./orphancheck.sh");
      printf("================================================================\n");
      break;
    default:
      printf("Invalid input.");
      printf("=============================================================\n");
  }
  return 0;
  }



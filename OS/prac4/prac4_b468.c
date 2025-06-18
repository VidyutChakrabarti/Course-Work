#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
int s;
printf("Enter 1 for FCFS scheduling.\nEnter 2 for SJF scheduling.\nEnter 3 for SRTF scheduling.\nEnter 4 for executing Round robin algorithm.\n");
printf("Enter your choice: ");
scanf("%d", &s);

switch(s){
/** [1] Executing first come first serve. (b468_fcfs.c)**/
case 1:
system("gcc b468_fcfs.c -o fcfs.out");
system("./fcfs.out");
printf("=============================================================\n");
break;
/** [2] Executing shortest job first algorithm. (b468_sjf.c) **/
case 2:
system("gcc b468_sjf.c -o sjf.out");
system("./sjf.out");
printf("=============================================================\n");
break;
/** [3] Executes b468_srtf.c. **/
case 3:
system("gcc b468_srtf.c -o srtf.out");
system("./srtf.out");
printf("=============================================================\n");
break;
/** [4] EXECUTES ROUND ROBIN (b468_rr.c) **/
case 4:
system("gcc b468_rr.c -o rr.out");
system("./rr.out");
printf("=============================================================\n");
break;
default:
printf("Invalid input.");
printf("==================================================\n");
}
return 0;
}

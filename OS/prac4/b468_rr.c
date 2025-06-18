#include<stdio.h>
#include "queue.h"

struct ans{
int id;
int bt;
int at;
int wt;
int tat;
};

void rrsched(struct Process process[], int n, int q){
struct ans schd[20];
float avgtat = 0;
float avgwt = 0;
struct Queue cqu;
createQueue(&cqu, 20);
int i;
int done = 0;
printf("\n======= READY QUEUE VISUALIZATION =======\n\n");
for(i=0; i<n; i++){
if(process[i].arrival_time == 0){
enqueue(&cqu, process[i]);
process[i].selected = 1;
printf("%d====>", process[i].process_id);
}}
int ct = 0;
while(done!=n){
struct Process r_pr = dequeue(&cqu);
if(r_pr.remaining_time>q){
ct+=q;
int inter_id = r_pr.process_id;
int id;
for(int h =0; h<n; h++){
if(process[h].process_id== inter_id){
id = h;
}
}
process[id].remaining_time -= q;
for(i = 0;i<n;i++){
if(process[i].arrival_time<=ct && process[i].remaining_time!=0 && process[i].selected !=1){
printf("%d====>", process[i].process_id);
enqueue(&cqu, process[i]);
process[i].selected = 1;
}
}
enqueue(&cqu, process[id]);
printf("%d====>", process[id].process_id);
}
else{
ct += r_pr.remaining_time;

int inter_id = r_pr.process_id;
int id;
for(int h =0; h<n; h++){
if(process[h].process_id== inter_id){
id = h;
}
}
process[id].remaining_time = 0;
process[id].tat = ct - process[id].arrival_time;
process[id].wt = ct - process[id].arrival_time - (process[id].burst_time);
avgwt+=ct - process[id].arrival_time - (process[id].burst_time);
avgtat += ct - process[id].arrival_time;
//printf("%d  %d   %d\n",id+1, process[id].tat, process[id].wt);

for(i = 0;i<n;i++){
if(process[i].arrival_time<=ct && process[i].remaining_time!=0 && process[i].selected !=1){
printf("%d====>", process[i].process_id);
enqueue(&cqu, process[i]);
process[i].selected = 1;
}
}
struct ans a;
a.id = id+1;
a.bt = process[id].burst_time;
a.at = process[id].arrival_time;
a.tat = process[id].tat;
a.wt = process[id].wt;
schd[done] = a; 
done +=1;
}
}
printf("\n\n======Processes Scheduled=======\n\n");
printf("pid    bt    at    wt    tat\n");
for(i = 0;i<n;i++){
printf("%d     %d      %d      %d      %d\n", schd[i].id, schd[i].bt, schd[i].at, schd[i].wt, schd[i].tat);
}
printf("\ntat: %.2f    wt: %.2f\n", avgtat/n, avgwt/n);
}


int main()
{

int n;
int q;
printf("\nExecuting Round Robin scheduling...\n");
// Input the number of processes 
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 printf("Enter the quantum: ");
 scanf("%d", &q);
 struct Process processes[n];

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].selected = 0;
    }

rrsched(processes, n, q);

  
      
  return 0;
}

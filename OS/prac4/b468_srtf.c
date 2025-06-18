#include<stdlib.h>
#include "queue.h"

// Structure to represent a process
struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int wt;
    int tat;
};

void insertionSort(struct Process arr[], int n)
{
    int i, key, j;
    struct Process k;
    for (i = 1; i < n; i++) 
    {
        key = arr[i].remaining_time;
        k = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j].remaining_time > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
       
        }
        
        arr[j+1] = k;
    }
   
}


void srtsched(struct Process processes[], int n){

int ct;
int total_time = 0;
int turnaround_time = 0;
int waiting_time = 0;
    
 // Calculate the total time required for all processes
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

for(ct = 0; ct<= total_time; ct++){
struct Process cur_proces[n];
int j = 0;
for(int i = 0; i< n; i++){
if(processes[i].arrival_time <= ct && processes[i].remaining_time != 0){
cur_proces[j] = processes[i];
j++;
}}

insertionSort(cur_proces, j);

int proces = cur_proces[0].process_id;
for(int h = 0; h<n; h++){
if(proces == processes[h].process_id){
processes[h].remaining_time = processes[h].remaining_time -1;
if(processes[h].remaining_time == 0){
turnaround_time += ct+1 - processes[h].arrival_time;
waiting_time+= ct - processes[h].arrival_time - (processes[h].burst_time - 1);
processes[h].wt = ct - processes[h].arrival_time - (processes[h].burst_time - 1);
processes[h].tat = ct+1 - processes[h].arrival_time;
}}
}
//printf("process id: %d executed for 1 unit.", cur_proces[0].process_id);
//printf("\n");
}
printf("\npid    arrival    burst    wait     tat\n");
for(int h = 0; h<n; h++){
printf("%d       %d         %d        %d       %d\n", h+1, processes[h].arrival_time, processes[h].burst_time, processes[h].wt, processes[h].tat);
}
printf("\ntotal turnaround time: %d\n", turnaround_time);
printf("total waiting time: %d\n", waiting_time);
printf("\naverage waiting time: %f", (float)waiting_time/n);
printf("\naverage turnaround time: %f\n", (float)turnaround_time/n);
}


int main(){
//struct Queue cqu;
//createQueue(&cqu, 20);
int n;

printf("\nExecuting SRTF scheduling...\n");
// Input the number of processes 
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 struct Process processes[n];

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

srtsched(processes, n);
return 0;
}





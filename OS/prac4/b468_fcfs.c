# include<stdio.h>
# include<stdlib.h>

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
};

void fcfs(struct Process processes[], int n){

int min_at = 100;
int adder = n;
int selected[20] = {0};
int wt, i;
int tat = 0;
float avgtat = 0;
float avgwt = 0;
printf("process   BT  AT  WT   TAT\n");
while(adder>0){
min_at = 100;
for(i =0; i<n; i++){
  if(processes[i].arrival_time< min_at && selected[i] == 0){
     min_at = processes[i].arrival_time;
   }
 }
for(i = 0; i<n; i++){
   if(processes[i].arrival_time == min_at){
   wt = tat;
   tat = tat + processes[i].burst_time;
   printf("%d         %d    %d   %d   %d\n",i+1, processes[i].burst_time, processes[i].arrival_time,wt - processes[i].arrival_time, tat - processes[i].arrival_time);
   avgtat+= tat - processes[i].arrival_time;
   avgwt+= wt - processes[i].arrival_time;
   selected[i] = 1;
   adder--;
  }
}
}
printf("\navg wt: %.2f,  avg tat: %.2f \n", avgwt/n, avgtat/n);

}

int main(){
// bt, at, pr
//int i;
//int process[5][3] = {{2, 0, 5}, {3, 2, 1}, {5, 3, 4}, {2, 1, 3}, {1, 0, 2}};

int n;
printf("\nExecuting fcfs scheduling...\n");
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

fcfs(processes, n);

return 0;
}


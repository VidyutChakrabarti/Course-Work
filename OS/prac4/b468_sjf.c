# include<stdio.h>
# include<stdlib.h>

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    
};

void insertionSort(struct Process prc[], int n)
{
    int i, key, j;
    struct Process k;
    for (i = 1; i < n; i++) 
    {
        key = prc[i].burst_time;
        k = prc[i];
        j = i - 1;
 
        while (j >= 0 && prc[j].burst_time > key) 
        {
            prc[j + 1] = prc[j];
            j = j - 1;
       
        }
        
        prc[j+1] = k;
    }
   
}
 
void sjf(struct Process process[], int n){
int i,j, sch;

int selected[20] = {0};

struct Process p_ready[n];
int t = 0;
int select = 0;
int wt;
float avgwt = 0.0;
float avgtat = 0.0;
int tat = 0;
printf("process   BT  AT  WT   TAT\n");

while(select!=n){
int prc = 0;
for(j = 0; j<n;j++){
if(process[j].arrival_time<=t && selected[j]!=1){
  p_ready[prc] = process[j];
  prc++;
  }
 }

insertionSort(p_ready , prc);
int select_id;
sch = p_ready[0].process_id;
for(i = 0; i<n;i++){
if(process[i].process_id == sch){
select_id = i;
selected[i] = 1;
break;
}
}
wt = tat;
tat = tat + process[select_id].burst_time;
printf("%d         %d    %d   %d   %d\n",sch, process[select_id].burst_time, process[select_id].arrival_time,wt - process[select_id].arrival_time, tat - process[select_id].arrival_time);
avgtat+= tat - process[select_id].arrival_time;
avgwt+= wt - process[select_id].arrival_time;
select++;
t+=process[select_id].burst_time;
}

printf("\navg wt: %.2f,  avg tat: %.2f \n", avgwt/n, avgtat/n);
}
 
 
int main(){
// bt, at, pr

//int process[5][3] = {{2, 1, 5}, {3, 2, 1}, {5, 3, 4}, {2, 0, 3}, {1, 0, 2}};

int n;
printf("\nExecuting SJF scheduling...\n");
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

sjf(processes, n);
return 0;
}


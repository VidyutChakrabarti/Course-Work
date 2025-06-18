#include<stdio.h>
struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int wt;
    int tat;
    int selected;
};

struct Queue {
struct Process q[30]; //define max as 30.
int CAP; //capacity
int front;
int back;
};

void createQueue(struct Queue *cqu, int capacity) {
cqu -> front = cqu -> back = -1;
cqu -> CAP = capacity;
}
int isEmpty(struct Queue cqu) {
if(cqu.front == -1) {
return 1;
}
return 0;
}
int isFull(struct Queue cqu) {
if((cqu.front == 0 && cqu.back == cqu.CAP) || (cqu.front == cqu.back + 1)) {
return 1;
}
return 0;
}

int enqueue(struct Queue *cqu,struct Process element) {
if(isFull(*cqu)) {
return -1;
}
cqu -> back = (cqu -> back + 1) % cqu -> CAP;
cqu->q[cqu->back]=element;
if(cqu ->front == -1) {
cqu -> front = 0;
}
return 1;
}

struct Process dequeue(struct Queue *cqu){
struct Process data;
struct Process null;
if(isEmpty(*cqu)){
printf("queue is empty");
return null;
}
data = cqu->q[cqu->front];
if(cqu->front==cqu->back){
cqu->front=cqu->back=-1;
}
else{
cqu->front=(cqu->front+1)%(cqu->CAP);
}
return data;
}



#include<stdio.h>
struct Queue {
int q[50]; //define max as 50; as variable not acceptable.
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

int enqueue(struct Queue *cqu,int element) {
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

int dequeue(struct Queue *cqu){
int data;
if(isEmpty(*cqu)){
printf("queue is empty");
return -1;
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

int frontval(struct Queue cqu){
if(cqu.front==-1 && cqu.back==-1){
printf("queue is empty");
return -1;
}
else{
int val = cqu.q[cqu.front];
return val;
}
}

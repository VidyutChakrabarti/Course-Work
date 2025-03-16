#include <stdio.h>
#include "Queue.h"
int main() {
struct Queue cqu;
createQueue(&cqu,20);
enqueue(&cqu,4);
enqueue(&cqu,8);
enqueue(&cqu,9);
dequeue(&cqu);
int v = frontval(cqu);
printf("the data is %d",v);
return 0;
}

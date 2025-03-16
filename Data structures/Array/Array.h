#include <stdio.h>
#define MAX 50
struct Array{
int capacity;
int arr[MAX];
int lastIndex;
};

void init(struct Array *a,int cap){
	a->capacity=cap;
	a->lastIndex=-1;
}

int isFull(struct Array a){
	if(a.lastIndex ==a.capacity-1){
		return 1;}
	else{
	return 0;
	}
}

int add(struct Array *a,int elem){
	if(isFull(*a)){
		return -1;
	}
	else{
		(a->lastIndex)++;
		a->arr[a->lastIndex]=elem;
		return 1;
	}
}

int getInput(char str[]){
	int n;
	printf("%s",str);
	scanf("%d",&n);
	return n;
}

void create(struct Array *a){

int elem=getInput("Enter An Integer : enter 999 to stop.");
	do{
		if(add(a,elem) == -1) {
		printf("Capacity reached");
		break;
		}
	elem=getInput("Enter An Integer : enter 999 to stop.");
	}while(elem!=999);

}

void print(struct Array a){
	printf("[");
	for(int i=0;i<=a.lastIndex;i++){
	printf("%d,",a.arr[i]);
	}
	printf("]");
}

int delete(struct Array *a,int index){
	if(index < 0 || index > a->lastIndex){
		return -1;
		}
	
		for(int i=index;i<a->lastIndex;i++){
				a->arr[i] = a->arr[i+1];				
		}
		(a->lastIndex)--;
		return 1;
}

void copy(struct Array *a, struct Array *source){
    if (a->lastIndex >= source->capacity) {
        printf("Error: Source array is small.\n");
    }

	else{

		for (int i = 0; i <= a->lastIndex; i++) {
			source->arr[i] = a->arr[i];
		}
		source->lastIndex = a->lastIndex;
	}
}






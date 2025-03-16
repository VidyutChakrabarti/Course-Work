#include "Array.h"
#include<stdio.h>
int main(){
	struct Array array;
	init(&array,10);
	isFull(array);
	add(&array,12);
	create(&array);
	print(array);

	printf("\nenter the index to delete: ");
	int index1=0;
	scanf("%d",&index1);

	int val = delete(&array,index1);
		if(val == -1 ){
			printf("\nError: Given index out of bound.\n");
			}
		
	print(array);

	struct Array source;
    init(&source, 10);
    copy(&array, &source);

    printf("\nSource Array: ");
    print(source);

    return 0;
}

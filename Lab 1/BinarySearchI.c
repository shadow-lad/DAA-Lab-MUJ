#include <stdio.h>

int search (int* array, int size, int key){

	int left = 0;
	int right = size - 1;

	while(left<=right){
		
		int middle = (left+right)/2;
	
		if(key == array[middle])
			return middle;
		else if(key < array[middle])
			right = middle - 1;
		else
			left = middle + 1;		
	
	}
	
	return -1;

}

int main(){

	printf("Enter size: ");
	int size;
	scanf("%d",&size);
	
	int array[size];
	printf("Enter sorted array: ");
	for(int i = 0; i < size; i++)
		scanf("%d",&array[i]);
		
	printf("Enter element to be searched: ");
	int key;
	scanf("%d",&key);
		
	int result = search(array,size,key);
	if(result == -1)
		printf("Element not present in array\n");
	else
		printf("Element found at position %d\n",result);
		
	return 0;

}

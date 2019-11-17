#include <stdio.h>

int search (int* array, int left, int right, int key){

	if(left<=right){
		
		int middle = (left+right)/2;
	
		if(key == array[middle])
			return middle;
		else if(key < array[middle])
			return search(array, left, middle - 1, key);
		else
			return search(array, middle + 1, right, key);		
	
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
		
	int result = search(array,0,size - 1,key);
	if(result == -1)
		printf("Element not present in array\n");
	else
		printf("Element found at position %d\n",result);
		
	return 0;

}

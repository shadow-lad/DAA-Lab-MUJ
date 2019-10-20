#include<stdio.h>

void quickSort(int* array, int left,int right){

	int i=left;
	int j=right;
	
	int pivot = array[(left+right)/2];
	
	while (i <= j){
		while (array[i] < pivot)
			i++;
    	while (array[j] > pivot)
    		j--;
    	if (i <= j){
			
			int temp = array[i];
			array[i]=array[j];
			array[j]=temp;			
			i++;
            j--;   	
		}

    }
    if(left<j)
       	quickSort(array,left,j);
    if(i<right)
       	quickSort(array,i,right);

}

void printArray(int* array, int size) { 
	 
	for (int i=0; i < size; i++) 
		printf("%d%c",array[i],(i+1==size?'\n':' ')); 
} 

int main(){ 
	
	printf("Enter size: ");
	int size;
	scanf("%d",&size);
	
	int array[size];
	
	printf("Enter array elements: ");
	for(int i =0; i < size; i++)
		scanf("%d",&array[i]); 
	
	quickSort(array, 0, size- 1); 
	printf("Sorted array: "); 
	printArray(array, size); 
	return 0; 
} 

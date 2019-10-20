#include <stdio.h>

void minHeapify(int* array, int size, int i){ 
    
    int min = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
  
    if (left < size && array[left] < array[min]) 
        min = left; 
  
    if (right < size && array[right] < array[min]) 
        min = right; 
  
    if (min != i){
     
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
     
        minHeapify(array, size, min); 
    
    } 

} 

void heapSort(int* array, int size){ 
    
    for (int i = size / 2 - 1; i >= 0; i--) 
        minHeapify(array, size, i); 
   
    for (int i=size-1; i>=0; i--){ 
      
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
   
        minHeapify(array, i, 0); 
    
    } 

} 

int main(){

	printf("Enter size: ");
	int size;
	scanf("%d",&size);
	
	int array[size];
	
	printf("Enter array elements: ");
	for(int i =0; i < size; i++)
		scanf("%d",&array[i]);
	
	heapSort(array,size);
	
	printf("Sorted Array: ");
	for( int i = 0; i < size ; i++ )
		printf("%d%c",array[i],(i+1==size?'\n':' '));

}

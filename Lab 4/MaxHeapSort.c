#include<stdio.h>

void maxHeapify(int* array, int size, int i){ 
    
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
  
    if (left < size && array[left] > array[max]) 
        max = left; 
  
    if (right < size && array[right] > array[max]) 
        max = right; 
  
    if (max != i){
     
        int temp = array[i];
        array[i] = array[max];
        array[max] = temp;
     
        maxHeapify(array, size, max); 
    
    } 

} 

void heapSort(int* array, int size){ 
    
    for (int i = size / 2 - 1; i >= 0; i--) 
        maxHeapify(array, size, i); 
   
    for (int i=size-1; i>=0; i--){ 
      
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
   
        maxHeapify(array, i, 0); 
    
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

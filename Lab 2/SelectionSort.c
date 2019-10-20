#include <stdio.h>
void sort(int* array, int size){

	for( int i = 0; i < size-1; i++ ){
	
		for (int j = i+1; j < size; j++ ){
		
			if(array[i]>array[j]){
			
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			
			}
		
		}	
	
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
	
	sort(array,size);
	
	printf("Sorted Array: ");
	for( int i = 0; i < size ; i++ )
		printf("%d%c",array[i],(i+1==size?'\n':' '));

}

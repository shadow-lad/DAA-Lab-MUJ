#include<stdio.h>

void merge(int* array, int left, int middle, int right){

	int size1=middle-left+1;
	int size2=right-middle;
	
	int leftArray[size1];
	int rightArray[size2];
	
	for(int i=0;i<size1;i++)
		leftArray[i]=array[left+i];
	for(int i=0;i<size2;i++)
		rightArray[i]=array[middle+1+i];
	
	int i=0;
	int j=0;
	int k=left;
	
	while(i<size1 && j<size2){
	
		if(leftArray[i] <= rightArray[j])
			array[k++]=leftArray[i++];
		else	
			array[k++]=rightArray[j++];
	
	}
	
	while(i<size1)
		array[k++]=leftArray[i++];
	
	while(j<size2)
		array[k++]=rightArray[j++];

}

void mergeSort(int* array,int left,int right){

	if(left<right){
	
		int middle = (left+right)/2;
		
		mergeSort(array,left,middle);
		mergeSort(array,middle+1,right);
		
		merge(array,left,middle,right);
	
	}

}

void main(){

	printf("Enter size: ");
	int size;
	scanf("%d",&size);
	
	int array[size];
	
	printf("Enter array elements: ");
	for(int i =0; i < size; i++)
		scanf("%d",&array[i]);
	
	mergeSort(array,0,size-1);
	
	printf("\nSorted Array:");
	for(int i=0;i<size;i++)
		printf("%d%c",array[i],(i+1==size?'\n':' '));

}

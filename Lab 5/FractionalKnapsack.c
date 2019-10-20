#include <stdio.h>

void swapInt(int* a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

void swapFloat(float* a, float* b){

    float temp = *a;
    *a =  *b;
    *b = temp;

}

void quickSort(float* array, int* array1, int* array2, int left,int right){

	int i=left;
	int j=right;
	
	float pivot = array[(left+right)/2];
	
	while (i <= j){
		while (array[i] < pivot)
			i++;
    	while (array[j] > pivot)
            j--;
    	if (i <= j){
			
			swapFloat(&array[i],&array[j]);
            swapInt(&array1[i], &array1[j]);
            swapInt(&array2[i], &array2[j]);	
			i++;j--;   	
		
        }

    }
    if(left<j)
       	quickSort(array,array1, array2, left,j);
    if(i<right)
       	quickSort(array,array1, array2, i,right);

}

int main(){

    printf("Enter number of objects: ");
    int size;
    scanf("%d",&size);

    int arrayPrice[size];
    int arrayWeight[size];
    float arrayPW[size];

    for(int i = 0; i < size; i++){

        printf("Enter Price, Weight for object %d: ",i+1);
        scanf("%d%d",&arrayPrice[i], &arrayWeight[i]);
        arrayPW[i] = (arrayPrice[i]*1.0)/arrayWeight[i];

    }

    printf("Enter max capacity of knapsack: ");
    int Weight;
    scanf("%d",&Weight);

    //Solution to Knapsack
    quickSort(arrayPW, arrayPrice, arrayWeight, 0, size-1);
    
    int current_weight = 0;
    float final_value = 0.0;
    int iterator = 0;
    while(current_weight < Weight){

        if (current_weight+arrayWeight[iterator] <= Weight){

            current_weight+=arrayWeight[iterator];
            final_value+=arrayPrice[iterator];

        } else {

            float remaining = Weight - current_weight;
            final_value += arrayPrice[iterator] * ((remaining)/arrayWeight[iterator]); 

        }

        iterator++;

    }

    printf("Maximum possible profit: %.2f\n",final_value);

}
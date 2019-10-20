#include<stdio.h>

void display(int* array, int size){

    printf("\n\nArray: ");
    for(int i = 0; i < size; i++)
        printf("%d%c",array[i],(i+1==size?'\n':' '));

}

void sort(int* array, int size){

    for(int i = 1; i < size; i++){

        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[++j] = key;

    }

}

int main(){

    int size;
    printf("Enter size of array: ");    
    scanf("%d",&size);

    int array[size];

    printf("Enter elements of array: ");

    for(int i = 0; i < size; i++)
        scanf("%d",&array[i]);
        
    sort(array, size);
    display(array, size);

}

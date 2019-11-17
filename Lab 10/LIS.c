#include<stdio.h>

int longestIncreasingSubsequenceLength(int *arr, int size){

    int tail[size];

    int len = 1;
    tail[0] = arr[0];
    for(int i = 1; i < size; i++){

        if(arr[i] < tail[0])
            tail[0] = arr[i];
        else if(arr[i] > tail[len-1])
            tail[len++] = arr[i];
        else{

            int left = -1,right = len-1;
            int key = arr[i];
            while(right - left > 1){

                int middle = left + (right - left)/2;
                if(arr[middle] >= key)
                    right = middle;
                else
                    left = middle;

            }
            
            tail[right] = arr[i];

        }

    }

    return len;

}

int main(){

    printf("Enter size of array: ");
    int size;
    scanf("%d",&size);

    int arr[size];
    printf("Enter array: ");
    for(int i = 0; i < size; i++)
        scanf("%d",&arr[i]);
    
    printf("Length of Longest Increasing Subsequence: %d\n",longestIncreasingSubsequenceLength(arr,size));

}
#include<stdio.h>
#define SIZE 100

int fib[SIZE];

void init_result(){

    for(int i = 0; i < SIZE; i++)
        fib[i] = -1;

}

int fibonacci(int n){

    if(fib[n] == -1){

        if(n <= 1)
            fib[n] = n;
        else
            fib[n] = fibonacci(n-1) + fibonacci(n-2);

    }

    return fib[n];

}

int main(){

    init_result();

    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    printf("Fib[%d] = %d\n",n, fibonacci(n));

}
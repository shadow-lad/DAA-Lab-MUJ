#include<stdio.h>

int fibonacci(int n){

    int fib[n+1];

    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i <= n; i++)
        fib[i] = fib[i-1]+fib[i-2];

    return fib[n];

}

int main(){

    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    printf("Fib[%d] = %d\n",n, fibonacci(n));

}
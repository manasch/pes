#include<stdio.h>
#include"5_header.h"

void main(){
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    if(prime(x))
        printf("The given number is a prime\nThe next prime is: %d",next(x));
    else
        printf("The given number is not a prime\nThe next prime is: %d",next(x));
}
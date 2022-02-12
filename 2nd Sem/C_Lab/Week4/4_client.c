#include<stdio.h>
#include"4_header.h"

void main(){
    int a,b;
    printf("Enter base value: ");
    scanf("%d",&a);
    printf("Enter power value: ");
    scanf("%d",&b);
    printf("The value of %d to the power %d is : %d",a,b,powr(a,b));
}
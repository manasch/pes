#include<stdio.h>
#include"2p_header.h"

void main(){
    int n;
    printf("Enter the number of Fibonacci numbers to populate: ");
    scanf("%d",&n);
    int a[n];
    fibb(a,n);
}
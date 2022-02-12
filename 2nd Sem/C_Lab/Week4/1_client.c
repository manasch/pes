#include<stdio.h>
#include"1_header.h"

void main(){
    int n;
    printf("Enter length of array: ");
    scanf("%d",&n);
    int a[n];
    read_arr(a,n);
    printf("\nReversing order with index\n");
    rev_index(a,n);
    printf("\nReversing order with pointer\n");
    rev_pointer(a,n);
}
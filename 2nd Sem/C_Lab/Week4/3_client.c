#include<stdio.h>
#include"3_header.h"

void main(){
    int n;
    printf("Enter the length of array: ");
    scanf("%d",&n);
    int a[n];
    get_arr(a,n);
    unique(a,n);
}
#include<stdio.h>
#include"1p_header.h"

void main(){
    int n;
    printf("Enter length of array: ");
    scanf("%d",&n);
    int a[n];
    get_arr(a,n);
    find(a,n);
}
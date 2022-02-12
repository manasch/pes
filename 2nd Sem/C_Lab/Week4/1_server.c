#include<stdio.h>
#include"1_header.h"

void read_arr(int a[],int n){
    printf("Enter the array elements: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Array Elements: \n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

void rev_index(int *a, int n){
    for (int i=n-1;i>=0;i--)
        printf("%d ",a[i]);
}

void rev_pointer(int *a, int n){
    for (int i=n-1;i>=0;--i)
        printf("%d ",*(a+i));
}
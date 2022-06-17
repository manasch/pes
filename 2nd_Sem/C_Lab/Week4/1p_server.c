#include<stdio.h>
#include"1p_header.h"

void get_arr(int a[],int n){
    printf("Enter the array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void find(int a[],int n){
    int max,min;
    max = a[0];
    min = a[0];
    for (int i=0;i<n;i++){
        if (a[i]>max)
            max = a[i];
        if (a[i]<min)
            min = a[i];
    }
    printf("Max and Min Values in the array are %d and %d",max,min);
}
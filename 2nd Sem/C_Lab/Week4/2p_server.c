#include<stdio.h>
#include"2p_header.h"

void fibb(int a[], int n){
    for(int i=0;i<n;i++){
        if (i<=1)
            a[i] = i;
        else if (i>1){
            a[i] = a[i-1] + a[i-2];
        }
    }

    for(int j=0;j<n;j++)
        printf("%d ",a[j]);
}
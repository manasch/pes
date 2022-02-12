#include<stdio.h>

void read_array(int *a,int n){
    for (int i = 0;i<n;i++){
        printf("Size of a in server %d\n",sizeof(a));
        printf("\nEnter the element: ");
        scanf("%d",&a[i]);
    }
}

void disp_array(int a[],int n){
    for (int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}
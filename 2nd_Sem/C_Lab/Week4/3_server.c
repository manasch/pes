#include<stdio.h>
#include"3_header.h"

void get_arr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
}

void unique(int a[],int n){
    printf("\nUnique Elements: ");

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(a[i] == a[j])
                ++cnt;
        }
        if (cnt == 1)
            printf("%d ",a[i]);
    }
}
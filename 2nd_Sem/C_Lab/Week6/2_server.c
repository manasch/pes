#include<stdio.h>
#include"2_header.h"

void read(int m, int n, int a[][n]){
    int r,c;
    for (r=0;r<m;r++)
        for (c=0;c<n;c++)
            scanf("%d",&a[r][c]);
}

void display(int m, int n, int a[][n]){
    int r,c;
    for (r=0;r<m;r++){
        for (c=0;c<n;c++)
            printf("%d ",a[r][c]);
        printf("\n");
    }
}

void transpose(int m, int n, int a[][n], int b[][n]){
    int r,c;
    for (r=0;r<m;r++)
        for (c=0;c<n;c++)
            b[r][c]=a[c][r];
}

int checksym(int m, int n, int a[][n], int b[][m]){
    int r,c;
    int issym = 1;
    for (r=0;r<m && issym;r++)
        for (c=0;c<n;c++)
            if (a[r][c]!=b[r][c]){
                issym = 0;
                break;
            }
    return issym;
}
#include<stdio.h>
#include"2_header.h"

int main(){
    int m,n;
    printf("Size of matrix m*n: ");
    printf("\nEnter values for m and n: ");
    scanf("%d %d",&m,&n);
    int a[m][n],b[m][n];
    printf("\nEnter the elements: \n");
    read(m,n,a);
    printf("\nThe given matrix is: \n");
    display(m,n,a);
    transpose(m,n,a,b);
    printf("\nMatrix b: \n");
    display(m,n,b);
    int sym=checksym(m,n,a,b);
    if(sym==1)
        printf("\nGiven matrix is symmetrical");
    else
        printf("\nGiven matrix is not symmetrical");

    return 0;
}
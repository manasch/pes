#include<stdio.h>
#include"2_header.h"

void main(){
    int n,r;
    printf("Enter positive n: ");
    scanf("%d",&n);
    printf("Enter positive r: ");
    scanf("%d",&r);

    printf("\nC(%d,%d) = %1d\n",n,r,fact(n)/(fact(r)*fact(n-r)));
}
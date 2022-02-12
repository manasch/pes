#include<stdio.h>
#include"myheader.h"

int main()
{
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    int res = fsum(a,b);
    printf("The sum is %d",res);
    return 0;
}
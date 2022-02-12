#include<stdio.h>
#include"hfile.h"

int main(){
    int a[10],n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("\nSize of a in main %d\n",sizeof(a));
    read_array(a,n);
    disp_array(a,n);
}
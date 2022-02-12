#include<stdio.h>
#include<stdlib.h>

int main(){
    int *x;
    int n,i;
    printf("Enter the no. of integers: ");
    scanf("%d",&n);

    x = (int*)malloc(n*sizeof(int));
    if (x==NULL)
        printf("\nNot allocated\n");
    else{
        printf("\nAllocated\n");
        for(i=0;i<n;i++)
            printf("%d ",*(x+i));
        printf("\nEnter the elements: ");
        for(i=0;i<n;i++)
            scanf("%d", x+i);
        printf("\nOutput\n");
        for(i=0;i<n;i++)
            printf("%d ",*(x+i));
    }
    return 0;
}
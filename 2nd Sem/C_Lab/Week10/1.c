#include<stdio.h>
#include"1.h"

int main()
{
    int a[] = {1, 10, 17, 20, 22, 26, 29, 50};
    int n = sizeof(a)/sizeof(*a);
    printf("Enter element to be found: ");
    int elem;
    scanf("%d", &elem);
    int pos = binarySearch(a, 0, n-1, elem, even);
    if(pos != -1)
        printf("\nElement is even and found at %d\n", pos);
    else
        printf("\nElement not found\n");
    
    pos = binarySearch(a, 0, n-1, elem, lessthan22);
    if(pos != -1)
        printf("\nElement is lesser than 22 and found at %d\n", pos);
    else
        printf("\nElement not found\n");
    
    return 0;
}
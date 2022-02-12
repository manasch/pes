#include<stdio.h>

int main()
{
    int n,i;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Enter the bit to be checked: ");
    scanf("%d",&i);
    if(n&(1<<i))
        printf("Bit is Set\n");
    else
        printf("But is not Set\n");
    printf("Enter the bit to be set: ");
    scanf("%d",&i);
    n |= (1<<i);
    printf("Number after setting the bit: %d\n",n);
    printf("Enter the bit to be cleared: ");
    scanf("%d",&i);
    n &= ~(1<<i);
    printf("Number after clearing the bit: %d\n",n);
    return 0;
}
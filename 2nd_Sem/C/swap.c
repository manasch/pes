//swap was done before with pass by value, haven't written that down
#include <stdio.h>
/*
void main()
{
    int a = 10;
    int *p = &a;
    printf("a = %d, addr a = %d\n",a,&a);
    printf("a = %d, addr a = %d\n",*p,p);
    printf("p = %d, addr p = %d\n",p, &p);

}*/

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void p_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a=10,b=20;
    printf("Values before swapping %d %d\n",a,b);
    swap(a,b);
    printf("Values after swapping %d %d\n",a,b);   
    p_swap(&a,&b);
    printf("Values after pointer swapping %d %d\n",a,b);   

    return 0; 
}
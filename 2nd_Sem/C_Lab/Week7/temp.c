#include<stdio.h>
#include<stdlib.h>


int main()
{

    int *p = (int*)calloc(5, sizeof(int)); 
    printf("\nsize of block %d\n", sizeof(p));
    *p = 10;

    printf("%d\n", *p);

    *(p+3)= 30;
    printf("\nBefore ralloc\n");    
    printf("%d %d %d %d\n", p, (p + 3), *p, *(p + 3)); 

    //p = p + 3;
    //printf("%d\n", *p); 

    p = (int*)realloc(p, 8*sizeof(int));
    printf("\nsize of block after realloc %d", sizeof(p));

    printf("\nAfter realloc\n");

    //*(p + 3) = 30000000;

    printf("%d %d %d %d\n", p, (p + 3), *p, *(p + 3)); 

    p = p + 3;
    
    printf("%d\n", p);

    printf("%d\n", *p); 

    p = p + 4;

    printf("%d\n", *(p-1));

    return 0;
}
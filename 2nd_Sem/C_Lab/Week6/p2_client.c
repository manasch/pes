#include<stdio.h>
#include"p2_header.h"

int main(){
    unit x,y;
    printf("Enter 1st distance\n");
    read(&x);
    printf("\nEnter 2nd distance\n");
    read(&y);

    unit s = addm(&x,&y);
    display(&s);
    return 0;
}
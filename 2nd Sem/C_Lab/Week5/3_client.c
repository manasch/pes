#include<stdio.h>
#include"3_header.h"
#define MAX 100

int main(){
    char s[MAX];
    printf("Enter a string: ");
    scanf("%[^\n]s",s);
    printf("\nBefore removing duplicates: %s",s);
    dup(s);
    printf("\nAfter removing duplicates: %s",s);
    return 0;
}
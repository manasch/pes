#include<stdio.h>
#include"2_header.h"

int main(){
    char s[50],a,b;
    printf("Enter a string: ");
    scanf("%[^\n]s",s);
    printf("\nEnter character to replace: ");
    fflush(stdin);
    scanf("%c",&a);
    printf("\nEnter character to replace with: ");
    fflush(stdin);
    scanf("%c",&b);
    printf("\nBefore Replace: %s",s);
    replace(s,a,b);
}
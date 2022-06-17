#include<stdio.h>
#include"p2_header.h"

int main(){
    char s1[50],s2[50];
    printf("Enter 1st string: ");
    scanf("%[^\n]s",s1);
    fflush(stdin);
    printf("Enter 2nd strinf: ");
    scanf("%[^\n]s",s2);
    printf("\n%d",strend(s1,s2));
    return 0;
}

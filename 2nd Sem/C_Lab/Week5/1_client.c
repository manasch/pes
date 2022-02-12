#include<stdio.h>
#include<string.h>
#include"1_header.h"

int main(){
    char s[20],a[20];
    printf("Enter a string: ");
    scanf("%s",s);
    rev(s,a);
    printf("The reversed string is: %s",a);
    if (!check(s,a))
        printf("\nIt is a palindrome\n");
    else    
        printf("\nIt is not a palindrome\n");
    return 0;
}
#include<stdio.h>
#include"4_header.h"

int main(){
    char s1[50],s2[50];
    int n;
    printf("Enter the 1st string: ");
    scanf("%s",s1);
    printf("Enter the 2nd string: ");
    scanf("%s",s2);
    printf("Enter the number of times to append: ");
    scanf("%d",&n);
    printf("Concatenated String: %s",mycat(s1,s2,n));
    return 0;
}
#include<stdio.h>
#include"p1_header.h"

int main(){
    char s[50],ns[50] = {};
    printf("Enter a string: ");
    scanf("%[^\n]s",s);
    dup(s,ns);
    char *temp = ns;
    while(*temp != '\0'){
        printf("%c occurs %d times\n",*temp,counter(*temp,s));
        temp+=1;
    }
    
    return 0;
}
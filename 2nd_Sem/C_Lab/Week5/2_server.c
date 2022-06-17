#include<stdio.h>
#include"2_header.h"

void replace(char *s, char a, char b){
    for(int i=0;s[i];i++){
        if (s[i]==a)
            s[i]=b;
    }
    printf("\nAfter replace: %s",s);
}
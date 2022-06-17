#include<stdio.h>
#include<string.h>
#include"1_header.h"

void rev(const char *s1, char *s2){
    int len = 0;
    while (*s1!='\0'){
        len++;
        s1++;
    }
    while (len>0){
        *s2++ = *(--s1);
        len--;
    }
    *s2 = '\0';
}

int check(char *s1, char *s2){
    while (*s1&&*s2&&*s1==*s2){
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}
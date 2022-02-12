#include<stdio.h>
#include"4_header.h"

void cat(char *d, const char *s){
    while(*d)
        d++;
    while(*d++=*s++);
}

char *mycat(char *d1, const char *s1, int n){
    for (int i=1;i<=n;i++)
        cat(d1,s1);
    return d1;
}
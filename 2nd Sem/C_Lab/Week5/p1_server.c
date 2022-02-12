#include<stdio.h>
#include<string.h>
#include"p1_header.h"

int in(char v,char *p){
    int flag = 1;
    while (*p && flag){
        if (*p++ == v)
            flag = 0;
    }
    return flag;
}

int counter(char ch, char *str){
    int count = 0;
    for(; *str; str++)
        if (*str == ch)
            count++;
    return count;
}

void dup(char *x, char *y){
    char *j = y;
    *j = *x;
    while (*x)
        if (in(*(++x), y)){
            j++;
            *j = *x;
        }
    *(++j) = '\0';
}

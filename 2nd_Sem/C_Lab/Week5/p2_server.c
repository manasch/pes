#include<stdio.h>
#include"p2_header.h"

int len(char *x){
    int cnt = 0;
    while(*x++){
        if(*x != '\0')
            cnt++;
    }
    return cnt + 1;
}

int strend(char *x, char *y){
    int i = len(x);
    int j = len(y);
    for (x=x+i, y=y+j; *x != ' ' && *y != ' ';x--,y--)
        if(*x != *y)    
            return 0;
    return 1;
}

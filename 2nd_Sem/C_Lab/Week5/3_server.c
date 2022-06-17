#include<stdio.h>
#include"3_header.h"

void remo(char *s,const char rem, int index){
    int i;
    while(s[index]!='\0'){
        if (s[index]==rem){
            i=index;
            while(s[i]!='\0'){
                s[i]=s[i+1];
                i++;
            }
        }
        else
            index++;
    }
}

void dup(char *s){
    int i=0;
    while(s[i]!='\0'){
        remo(s,s[i],i+1);
        i++;
    }
}
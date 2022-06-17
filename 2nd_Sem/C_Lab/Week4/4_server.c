#include<stdio.h>
#include"4_header.h"

int powr(int a,int b){
    return b == 0 ? 1 : powr(a,b-1)*a;
}
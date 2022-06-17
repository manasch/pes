#include<stdio.h>
#include"2_header.h"

int fact(int x){
    return x == 0 ? 1 : fact(x-1)*x;
}
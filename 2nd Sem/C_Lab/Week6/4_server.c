#include<stdio.h>
#include"4_header.h"

cmx addc(cmx n1, cmx n2){
    cmx temp;

    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return temp;
}

cmx diff(cmx n1, cmx n2){
    cmx temp;

    temp.real = n1.real - n2.real;
    temp.imag = n1.imag - n2.imag;
    return temp;
}
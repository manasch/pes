#include<stdio.h>
#include"4_header.h"

int main(){
    cmx n1,n2,sum,sub;
    printf("Enter the 1st complex number (real and imaginary): ");
    scanf("%f %f",&n1.real,&n1.imag);
    printf("Enter the 2nd complex number (real and imaginary): ");
    scanf("%f %f",&n2.real,&n2.imag);
    sum = addc(n1,n2);
    sub = diff(n1,n2);
    printf("\nSum = %.1f+%.1fi\n",sum.real,sum.imag);
    printf("\nDifference = %.1f+%.1fi\n",sub.real,sub.imag);

    return 0;
}
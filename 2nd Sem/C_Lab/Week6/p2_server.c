#include<stdio.h>
#include"p2_header.h"

void read(unit *m){//m = measure
    printf("Enter feet: ");
    scanf("%d",&m->feet);
    printf("Enter inches: ");
    scanf("%f",&m->inch);
}

unit addm(unit *m1, unit *m2){
    unit sum;
    sum.feet = m1->feet + m2->feet;
    sum.inch = m1->inch + m2->inch;

    if (sum.inch >= 12.0f){
        sum.inch-=12.0f;
        sum.feet+=1;
    }
    return sum;
}

void display(unit *m){
    printf("\nSum = %d' %.1f''",m->feet,m->inch);
}
#include<stdio.h>
#include"3_header.h"

void read(date_info *d){
    scanf("%d/%d/%d",&d->dd,&d->mm,&d->yy);
}

void display(date_info *d){
    printf("%d/%d/%d\n",d->dd,d->mm,d->yy);
}

int comp(date_info *d1, date_info *d2){
    int res;
    if (d1->dd == d2->dd && d1->mm == d2->mm && d1->yy == d2->yy)
        res = 0;
    else if (d1->yy>d2->yy || d1->yy==d2->yy && d1->mm>d2->mm || d1->yy==d2->yy && d1->mm==d2->mm && d1->dd>d2->dd)
        res = 1;
    else
        res = -1;
    return res;
}
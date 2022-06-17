#include<stdio.h>
#include"3_header.h"

int main(){
    date_info d1,d2;

    printf("Enter the date1 in dd/mm/yyyy: ");
    read(&d1);
    printf("Date 1: ");
    display(&d1);
    printf("\nEnter the date2 in dd/mm/yyyy: ");
    fflush(stdin);
    read(&d2);
    printf("Date 2: ");
    display(&d2);

    int res=comp(&d1,&d2);
    if (res == 0)
        printf("\nDate 1 is equal to Date 2");
    else if (res > 0)
        printf("\nDate 1 is greater to Date 2");
    else
        printf("\nDate 1 is less to Date 2");

    return 0;
}
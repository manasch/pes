#include<stdio.h>

int main()
{
    int dd,mm,yy;
    int max1;
    printf("Enter the date: ");
    scanf("%d",&dd);
    printf("Enter the month: ");
    scanf("%d",&mm);
    printf("Enter the year: ");
    scanf("%d",&yy);

    if (mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
        max1=31;
    else if (mm==4||mm==6||mm==9||mm==11)
        max1=31;
    else if (yy%3==0&&yy%100!=0||yy%400==0)
        max1=29;
    else
        max1=29;

    if(mm<1||mm>12)
        printf("Month is invalid");
    else if(dd<1||dd>max1)
        printf("Date is invalid");
    else if(dd==max1 && mm!=12)
    {
        dd=1;
        mm=mm+1;
        printf("Date is valid and next date is : %d/%d/%d",dd,mm,yy);
    }
    else
    {
        dd+=1;
        printf("Date is valid and next date is : %d/%d/%d",dd,mm,yy);       
    }
}
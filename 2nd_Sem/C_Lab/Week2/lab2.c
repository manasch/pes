#include<stdio.h>
/*
int main()
{
    char c;
    printf("Enter characters to convert to upper case\n");

    while((c=getchar())!='\n')
    {
        if (c>='a'&&c<='z')
        {
            c=(c+'A'-'a');
        }
    putchar(c);
    }
    return 0;
}*/
/*
int main()
{
    int i,n;
    printf("Enter the valye of n:\n");
    scanf("%d", &n);
    printf("Multiplication table for %d is \n",n);
    for(i = 1;i<=10;i++)
        printf("\n%d*%d=%d",n,i,n*i);
    return 0;
}*/
/*
int main()
{
    int r,i,j;
    printf("Enter the number of rows\n");
    scanf("%d", &r);

    for(i=1;i<=r;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}*/
/*
int main()
{
    char operator;
    double first, second;;
    printf("Enter the operator(+,-,*):\n");
    scanf("%c",&operator);
    printf("Enter the value of two operands\n");
    scanf("%lf%lf",&first,&second);
    switch(operator)
    {
        case'+':
            printf("%.1lf+%.1lf=%.1lf",first,second,first+second);
            break;
        case'-':
            printf("%.1lf-%.1lf=%.1lf",first,second,first-second);
            break;
        case'*':
            printf("%.1lf*%.1lf=%.1lf",first,second,first*second);
            break;   
        default:
            printf("Invalid");               
    }
}*/
/*
int main()
{
    int dd,mm,yy;
    int max1;
    printf("Enter the date");
    scanf("%d",&dd);
    printf("Enter the month");
    scanf("%d",&mm);
    printf("Enter the year");
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
        printf("Date is valid and next date is :%d%d%d");
    }

}*/

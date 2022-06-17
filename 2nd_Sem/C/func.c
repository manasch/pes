#include<stdio.h>
/*
int display1(int val)
{
    int a = 10, b = 20;
    float c = 10.1;
    printf("\nInside display 1 %d", val);
}



int main()
{
    display1(25);
    //printf("%d",d);
    return 0;
}*/
/*

int add(int, int);
int sub(int, int);
int mul(int, int);

int main()
{
    int a =5, b = 2;
    int res_a = add(a,b);
    int res_s = sub(a,b);
    int res_m = mul(a,b);
    printf("Sum = %d, Product = %d, Difference = %d", res_a, res_m, res_s);
    return 0;
}

int add(int p, int r)
{
    int res = p+r;
    return res;
}

int mul(int p, int r)
{
    int res = p*r;
    return res;
}

int sub(int p, int r)
{
    int res = p-r;
    return res;
}*/

void f1();
void f2(int);
int f3(int);
int main()
{
    int a = 100;

    printf("a in main = %d", a);
    //f1();
    //f2(a);
    a = f3(a);
    printf("\na after func call = %d", a);
    return 0;
}

void f1()
{
    int a = 200;
}

void f2(int a)
{
    a = 200;
}

int f3(int a)
{
    a = 200;
    return a;
}
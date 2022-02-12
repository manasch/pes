#include<stdio.h>
/*
int fact(int);
int main(){
    int a;
    printf("Enter the number whose factorial is to be found: ");
    scanf("%d",&a);
    printf("Factorial of %d = %d",a,fact(a));
    return 0;
}

int fact(int a){
    if (a == 0)
        return 1;
    else if (a == 1)
        return 1;
    else if (a<0)
        return 0;
    else 
    return a*fact(a-1);
}*/
/*
int what(int);
int main()
{
    int n =10;
    printf("%d",what(n));
    return 0;
}

int what(int n)
{
    if(!n)
        return 0;
    else if (!(n%2))
        return what(n/2);
    else
        return 1 + what(n/2);
}*/

//sum 
/*
int nsum(int n);

int main()
{
    int s;
    printf("Enter the number: ");
    scanf("%d", &s);

    printf("The sum of numbers till %d = %d",s,nsum(s));
    return 0;
}

int nsum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + nsum(n-1);
}*/
/*
void find_addr(int *);
int main()
{
    int num = 10;
    printf("The adress is %d", &num);

    find_addr(&num);
}

void find_addr(int *n)
{
    printf("The address from the function: %d",n);
}*/

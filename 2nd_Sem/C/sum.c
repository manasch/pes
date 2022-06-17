#include<stdio.h>

int main()
{
    int a,b;
    char s;
    printf("Enter the first number:\n");
    scanf("%d", &a);
    printf("Enter the 2nd number:\n");
    scanf("%d", &b);
    printf("Enter the operation to perform:\n");
    scanf("%s", s);
    if (s == "a")
    {
        printf("%d", a+b);
    }
    else if (s == "m")
    {
        printf("%d",a*b);
    }
    else if (s == "s")
    {
        printf("%d",a-b);
    }
    return 0;
}
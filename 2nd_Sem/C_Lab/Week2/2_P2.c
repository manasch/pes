#include<stdio.h>

int main()
{
    char a,b;
    a=b=' ';
    printf("Enter string: ");
    while(a!='\n')
    {
        b=a;
        a=getchar();
        if(a!=b)
        printf("%c",a);
    }
    return 0;
}
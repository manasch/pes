#include<stdio.h>
#include<string.h>

int main()
{
    char ch;

    ch = getc(stdin);
    putc(ch, stdout);
    printf("\n%d",ch);
}
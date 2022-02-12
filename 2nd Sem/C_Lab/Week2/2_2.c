#include<stdio.h>

int main()
{
    char ch;
    printf("Enter characters to convert to upper case: ");
    while ((ch=getchar())!='\n' )
    {
        if (ch>='a'&&ch<='z')
            ch += 'A'-'a';
        
        putchar(ch);
    }
    return 0;
}
#include<stdio.h>

/*
int main()
{
    char ch;
    printf("Enter a string: ");
    scanf("%c", &ch);
    putchar(ch);
    
    while ((ch=getchar())!=EOF)
    {
        putchar(ch);
    }
    
}*/

int main()
{
    int flag = 0;
    char ch;
    int nc = 0;
    int nw = 0;
    int nl = 0;

    while((ch = getchar())!=EOF)
    {
        nc++;
        if (ch == '\n')
            nl++;
        if (flag && (ch == '\n' || ch == ' ' || ch == '\t'))
        {
            flag = 0;nw++;
        }
        if (!(ch == '\n' || ch == ' ' || ch == '\t'))
            flag =1;
    }

    printf("\nNo. of char: %d",nc);
    printf("\nNo. of words: %d",nw);
    printf("\nNo. of lines: %d",nl);
}
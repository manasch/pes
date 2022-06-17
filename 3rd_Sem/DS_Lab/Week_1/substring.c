#include<stdio.h>
#include<stdlib.h>

int search(char *, char *);

int main()
{
    char main[100], sub[100];
    printf("Enter the main string: ");
    scanf("%[^\n]s", main);
    fflush(stdin);

    printf("Enter the substring to be searched: ");
    scanf("%s", sub);

    int result = search(main, sub);

    if (result == 1)
        printf("\nTrue");
    else
        printf("\nFalse");
}

int search(char *main, char *sub)
{
    if (*main == '\0')
        return 0;
    
    if (*sub == '\0')
        return 1;
    
    if (*main == *sub)
        return search(main + 1, sub + 1);
    
    return 0;
}
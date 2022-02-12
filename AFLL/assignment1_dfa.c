// DFA , L = {w | w belongs to abab^n or aba^n, n >= 0}

#include<stdio.h>
#include<stdlib.h>

typedef struct state
{
    int value;
    struct state *next;
} state;


int main()
{
    char str[10];
    printf("\nEnter the string: ");
    scanf("%s", str);


}
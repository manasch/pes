// converting normal expression to postfix expression


#include<stdio.h>
#include<stdlib.h>

void convert_postfix(char *, char *);
void push(char *, int *, char);
char pop(char *, int *);
int main()
{
    char infix[10], postfix[10];
    printf("\nEnter valid infix expression: ");
    scanf("%s", infix);
    convert_postfix(infix, postfix);
    printf("\nThe postfix equivalent: %s", postfix);
}

void convert_postfix(char *infix, char *postfix)
{
    char s[10]; // stack of characters
    int top, i, j;
    top = -1;
    char ch;
    i = j = 0;
    push(s, &top, '#'); // push # to stack

    while(infix[i] != '\0')
    {
        ch = infix[i];
        while(stack_prec(peep(s, top)) > input_prec(ch))
            postfix[j++] = pop(s, &top);
        if(input_prec(ch) < stack_prec(peep(s,top)))
            push(s, &top, ch);
        else
            pop(s, &top); //happens when you compare '(' with ')'
        i++;
    }
}
// evaluation of postfix
/*
    a + b * c / d
    a + b c * / d
    a + b c * d /
    a b c * d / + --> Taken as input to the stack
*/
#include<stdio.h>
#include<stdlib.h>

void push(int *, int *, int);
int pop(int *, int *);
int isoper(char);
int postfix_eval(char *);

int main()
{
    char postfix[100];
    printf("\nEnter a valid postfix expression: ");
    scanf("%s", postfix);
    int result = postfix_eval(postfix);
    printf("\nResult = %d", result);
}

int postfix_eval(char *postfix)
{
    int s[10]; // stack of integers
    int top = -1, i = 0;
    char ch;
    int a;
    int op1, op2, r;

    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        if(isoper(ch)) // if it is an operator
        {
            op1 = pop(s, &top);
            op2 = pop(s, &top);
            switch (ch)
            {
            case '+':
                r = op1 + op2;
                push(s, &top, r);
                break;
            
            case '-':
                r = op2 - op1;
                push(s, &top, r);
                break;
            
            case '*':
                r = op1 * op2;
                push(s, &top, r);
                break;
            
            case '/':
                r = op2 / op1;
                push(s, &top, r);
                break;

            // case '$':
            //     r = op2 ^ op1;
            //     push(s, &top, r);
            //     break;
            
            default:
                break;
            }
        }
        else // if operand
        {
            printf("\n%c = ", ch);
            scanf("%d", &a);
            push(s, &top, a);
        }
        i++;
    }    
    return (pop(s, &top));
}

void push(int *s, int *t, int x)
{
    ++*t; //increament top
    s[*t] = x;
}

int pop(int *s, int *t)
{
    int x;
    x = s[*t];
    --*t; // decrement top
    return x;
}

int isoper(char ch)
{
    if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
        return 1;
    
    return 0;
}
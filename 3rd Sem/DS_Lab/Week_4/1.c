#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Infix to Postfix
// gcc -o 1.out 1.c -lm

int stack_precedence(char);
int input_precedence(char);
void convert_postfix(char *, char *);
char peep(char *, int);
void push(char *, int *, char);
char pop(char *, int *);
void push2(int *, int *, int);
int pop2(int *, int *);
int isoper(char);
int evaluate_postfix(char *);

int main()
{
    char infix[20], postfix[20];
    printf("\nEnter the infix expression:\n");
    scanf("%s", infix);

    convert_postfix(infix, postfix);
    printf("\nPostfix expression: %s", postfix);

    int result = evaluate_postfix(postfix);
    printf("\nResult = %d\n", result);

    return 0;
}


int isoper(char ch)
{
    if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '$'))
        return 1;
    return 0;
}


int input_precedence(char x)
{
    switch (x)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 3;
    case '$': return 6;
    case '(': return 9;
    case ')': return 0;
    default: return 7;
    }
}


int stack_precedence(char x)
{
    switch (x)
    {
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 4;
    case '$': return 5;
    case '(': return 0;
    case '#': return -1;
    default: return 8;
    }
}


void push(char *s, int *top, char x)
{
    ++*top;
    s[*top] = x;
}


char pop(char *s, int *top)
{
    char x;
    x = s[*top];
    --(*top);
    return x;
}


void push2(int *s, int *t, int x)
{
    ++*t; //increament top
    s[*t] = x;
}

int pop2(int *s, int *t)
{
    int x;
    x = s[*t];
    --*t; // decrement top
    return x;
}


char peep(char *s, int top)
{
    return s[top];
}


void convert_postfix(char *infix, char *postfix)
{
    char s[10];
    char ch;
    int top = -1;
    int i = 0;
    int j = 0;

    push(s, &top, '#');
    
    while (infix[i] != '\0')
    {
        ch = infix[i];
        while (stack_precedence(peep(s, top)) > input_precedence(ch))
            postfix[j++] = pop(s, &top);
        
        if (input_precedence(ch) > stack_precedence(peep(s, top)))
            push(s, &top, ch);
        else
            pop(s, &top); // when ( and ) are compared
        i++;
    }

    while (peep(s, top) != '#') // pop out the remaining elements from the stack
        postfix[j++] = pop(s, &top);
    postfix[j] = '\0';
}

int evaluate_postfix(char *postfix)
{
    int s[20];
    char ch;
    int top = -1;
    int i = 0;
    int op1, op2, r;

    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        if (isoper(ch))
        {
            op1 = pop2(s, &top);
            op2 = pop2(s, &top);

            switch (ch)
            {
            case '+':
                r = op1 + op2;
                push2(s, &top, r);
                break;
            
            case '-':
                r = op2 - op1;
                push2(s, &top, r);
                break;
            
            case '*':
                r = op1 * op2;
                push2(s, &top, r);
                break;
            
            case '/':
                r = op2 / op1;
                push2(s, &top, r);
                break;
               
            case '$':
            	r = pow(op2, op1);
            	push2(s, &top, r);
            	break;
            
            default:
                break;
            }
        }
        else
        {
            push2(s, &top, ch - '0');
        }
        i++;
    }
    return pop2(s, &top);
}

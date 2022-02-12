#include"stack.h"

void push(stack_t *ptr_st, int key)
{
    if (ptr_st->top == ptr_st->size - 1) // Stack is full
        printf("\nStack Overflow");
    else
    {
        ptr_st->top++;
        ptr_st->s[ptr_st->top] = key;
    }
}

int pop(stack_t *ptr_st)
{
    if (ptr_st->top == -1) // Stack is empty
    {
        printf("\nStack Underflow");
        return -1;
    }

    int key = ptr_st->s[ptr_st->top];
    ptr_st->top--;
    return key;
}

void display(stack_t *ptr_st)
{
    if (ptr_st->top == -1)
        printf("\nEmpty Stack");
    else
    {
        printf("\n");
        for (int i = ptr_st->top; i >= 0; i--)
            printf("%d ", ptr_st->s[i]);
    }
}
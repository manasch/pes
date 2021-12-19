#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int *s; //stack of integers
    int size; //tells the size of the stack
    int top; //index to the top element
};

typedef struct stack stack_t;

void push(stack_t *, int);
int pop(stack_t *); // returns the element that was popped
void display(stack_t *);
//int peek(stack_t *); //returns the top element
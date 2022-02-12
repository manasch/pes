#include "stack.h"


void init(stack_t *ptr_st)
{
	printf("Enter the size..");
	scanf("%d",&ptr_st->size);
	ptr_st->s= (int*)malloc(sizeof(int)*(ptr_st->size));
	
	ptr_st->top=-1;
}
	
void push(stack_t *ptr_st, int key)
{
	if(ptr_st->top==ptr_st->size-1)//check for stack overflow
		printf("\nStack full..\n");
	else
	{
		ptr_st->top++;  //increment top
		ptr_st->s[ptr_st->top]=key;//insert the element
	}
}
	
	int pop(stack_t *ptr_st)
	{
		int key;
		if(ptr_st->top==-1) // check for stack underflow
		{
			printf("Stack empty..\n");
			return -1;
		}
		key= ptr_st->s[ptr_st->top]; //get the element
		ptr_st->top--; // decrement top
		return key;
	}
		
	void display(stack_t *ptr_st)
	{
		int i;
        if(ptr_st->top==-1)
			printf("\nEmpty stack..\n");
		else
		{
			for(i=ptr_st->top; i>=0;i--)
				printf("%d ",ptr_st->s[i]);
		}
	}
			
			
		
	
			
    		
		
		
			
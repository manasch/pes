#include "linkedstack.h"

void init(stack_t *ptr_st)
{
	ptr_st->top=NULL;
}

void push(stack_t *ptr_st, int key)
{
	node_t *temp;
	
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=key;
	temp->link=NULL;
	
	temp->link=ptr_st->top;
	ptr_st->top=temp;
}
	
	
	int pop(stack_t *ptr_st)
	{
		node_t *pres;
		int key;
		if(ptr_st->top==NULL)
		{
			printf("Empty stack..");
			return -1;
		}
		else
		{
			pres=ptr_st->top;
			key=pres->key;
			ptr_st->top=pres->link;
			free(pres);
			return key;
		}
	}
			
	void display(stack_t *ptr_st)
	{
		int i;
		node_t *pres;
        if(ptr_st->top==NULL)
			printf("\nEmpty stack..\n");
		else
		{
			pres=ptr_st->top;
			while(pres!=NULL)
			{
				printf("%d->",pres->key);
				pres=pres->link;
		   }
	   }
	}
			
			
		
	
			
    		
		
		
			
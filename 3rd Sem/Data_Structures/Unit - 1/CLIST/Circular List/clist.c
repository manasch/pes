#include "clist.h"

void init_list(clist_t *ptr_list)
{
	ptr_list->last=NULL;
}

  	void insert_front(clist_t *ptr_list, int key)
	{
		node_t *temp, *last;
		
		temp=(node_t*)malloc(sizeof(node_t));
		temp->key=key;
		temp->link=temp;
		
		last=ptr_list->last;
		
		if(last==NULL)
			ptr_list->last=temp;
		else
		{
			temp->link=last->link;
			last->link=temp;
		}
	}
			
			
		void insert_end(clist_t *ptr_list, int key)
	{
		node_t *temp, *last;
		
		temp=(node_t*)malloc(sizeof(node_t));
		temp->key=key;
		temp->link=temp;
		
		last=ptr_list->last;
		
		if(last==NULL)
			ptr_list->last=temp;
		else
		{
			temp->link=last->link;
			last->link=temp;
			ptr_list->last=temp;
		}
	}
		
		void display(clist_t *ptr_list)
		{
			node_t *last, *pres;
			
			last=ptr_list->last;
						
			if(last==NULL)
				printf("\nEmpty list.\n");
			else
			{
			  pres=last->link;
			  while(pres!=last)
			  {
				printf("%d ->",pres->key);
				pres=pres->link;
			  }
			printf("%d ",pres->key);
		  }
		}		
			
	void delete_node(clist_t *ptr_list, int key)
		{
			node_t *last,*pres,*prev;
			
			last=ptr_list->last;
			prev=last;
			pres=last->link;
			
			while((pres->key!=key)&&(pres!=last))
			{
				prev=pres;
				pres=pres->link;
			}
			if(pres->key==key)
			{
				if(pres->link==pres)//only one node
					ptr_list->last=NULL;
				else
				{
					prev->link=pres->link;
				    if(pres==last)
						ptr_list->last=prev;
				}
				free(pres);
			}
			else
				printf("Key not found..\n");
		}
				
				
			
				
				
			
			
			
			
			
			
				
				
			
			
			
			
			

			
			
			
		
	
		
			
		
		
		
  
	  
	  
	  
	  
		
		
		
		
			
		
		
		
	   
			   
			   
		   
		   
	   
		   
		   
	   
	   
		
	   
	   
	   
		 
	  
	  
	  

	
		  
		  
	  
	  
  


			
		
		
	
			
			
	
	
	
	
	
	
	
	
	
	

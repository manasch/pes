#include"dll.h"

void init_list(dlist_t * ptr_list)
{
	ptr_list->head=NULL;
}

void insert_tail(dlist_t *ptr_list, int key)
{
     node_t *temp,*pres;
	
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=key;
	temp->prev=temp->next=NULL;
	
	//if list empty?
	if(ptr_list->head==NULL)
		ptr_list->head=temp;
	else
	{
		pres=ptr_list->head;
		while(pres->next!=NULL)
		  pres=pres->next;
	  pres->next=temp;
	  temp->prev=pres;
	}
}
	  
	void delete_first(dlist_t *ptr_list)
	{
		node_t *pres;
		
        pres=ptr_list->head; 
		
		//if only one node
		if(pres->next==NULL)
			ptr_list->head=NULL;
		else
		{
			 pres->next->prev=NULL;
			 ptr_list->head=pres->next;
		}
		free(pres);
	}
			
	void delete_last(dlist_t *ptr_list)
	{
		node_t *pres;
		
        pres=ptr_list->head; 
		
		//if only one node
		if(pres->next==NULL)
			ptr_list->head=NULL;
       else
	   {
           while(pres->next!=NULL)
			   pres=pres->next;
		   pres->prev->next=NULL;
	   }
	   free(pres);
	}
	   
	void delete_node(dlist_t *ptr_list	, int key)
	{
		node_t *pres;
		
        pres=ptr_list->head;//copy address of first node 
		
		//move forward until the node is found
		//or you go beyond the last node
		
		while((pres!=NULL)&&(pres->key!=key))
			pres=pres->next;
		
		if(pres!=NULL)//node found
		{
			//where?
		//only node
           if((pres->prev==NULL)&&(pres->next==NULL))
			ptr_list->head=NULL;
		  else if(pres->prev==NULL)//first node
		  {
			pres->next->prev=NULL;
			ptr_list->head=pres->next;
		  }
		else if (pres->next==NULL)//last node
			pres->prev->next=NULL;
		 else // middle node
		 {
			pres->prev->next=pres->next;
			pres->next->prev=pres->prev;
		  }
		  free(pres);
		}
		else //pres==NULL
		 printf("Node not found..\n");
	}
			
			
	void delete_pos(dlist_t *ptr_list	, int pos)
	{
		node_t *pres;
		int i;
        pres=ptr_list->head;//copy address of first node 
		
		//move forward until the position is found
		//or you go beyond the last node
		i=1;
		while((pres!=NULL)&&(i<pos))
		{
			pres=pres->next;
			i++;
		}
		
		if(pres!=NULL)//position found
		{
			//where?
		//only node
           if((pres->prev==NULL)&&(pres->next==NULL))
			ptr_list->head=NULL;
		  else if(pres->prev==NULL)//first position
		  {
			pres->next->prev=NULL;
			ptr_list->head=pres->next;
		  }
		else if (pres->next==NULL)//last position
			pres->prev->next=NULL;
		 else // middle position
		 {
			pres->prev->next=pres->next;
			pres->next->prev=pres->prev;
		  }
		  free(pres);
		}
		else //pres==NULL
		 printf("Invalid position \n");
	}	
			
		
		
		
		
		
		
		
		
		
		
		
		

			
			
			
			
			
			
		
		
		
		
		



		

		   
			
			
		
		
		
		
		


		
			
		
		
		

void insert_head(dlist_t *ptr_list, int key)
{
	node_t *temp;
	
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=key;
	temp->prev=temp->next=NULL;
	
	//if list empty?
	if(ptr_list->head==NULL)
		ptr_list->head=temp;
	else//list present
	{
		temp->next=ptr_list->head;
		ptr_list->head->prev=temp;
		ptr_list->head=temp;
	}
}
		
		
		
		
void display(dlist_t *ptr_list)
{
	node_t *pres;
	
	pres=ptr_list->head;
	
	if(pres==NULL)
		printf("Empty List..\n");
	else
	{
		while(pres!=NULL)
		{
			printf("%d<=>",pres->key);
			pres=pres->next;
		}
	}
}
		
	
		 
		 
		 
	 
		 
	 
	 
	
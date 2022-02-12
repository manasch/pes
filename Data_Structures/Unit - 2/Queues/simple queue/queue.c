#include "queue.h"


void init(queue_t *ptr_q)
{
	
	printf("Enter the max size of the queue,,");
	scanf("%d",&ptr_q->size);
	
	ptr_q->item=(int*)malloc(sizeof(int)*(ptr_q->size));
	ptr_q->f=-1;
	ptr_q->r=-1;
}
	
	int qinsert(queue_t *ptr_q, int key)
	{
		//check for queue overflow
		
		if(ptr_q->r==ptr_q->size-1)
		{
			printf("Queue full..cannot insert..\n");
		    return -1;
	   }
	   ptr_q->r++;  //increment rear
	   ptr_q->item[ptr_q->r]=key;
	   if(ptr_q->f==-1)//if first element
		ptr_q->f=0;
	}
	   
	   int qdelete(queue_t *ptr_q)
	   {
		   int key;
		  if(ptr_q->f==-1)
		  {
			  printf("Empty queue...\n");
		      return -1;
	      }
		  key = ptr_q->item[ptr_q->f];
		  if(ptr_q->f==ptr_q->r)//if only one element
		    ptr_q->f=ptr_q->r=-1;
		  else
			  ptr_q->f++; //increment front
		  return key;
	   }
	   
void display(queue_t *ptr_q)
{
	int i;
	if(ptr_q->f==-1)
		printf("empty queue..\n");
	else
	{
		for(i=ptr_q->f;i<=ptr_q->r;i++)
			printf("%d  ",ptr_q->item[i]);
		printf("\n");
	}
}
		
	
	
      













/*void init(queue_t *ptr_q)
{
 ptr_q->f=ptr_q->r-1;
 
  printf("Enter the size of the queue..");
  scanf("%d",&ptr_q->size);

  q.item=(int*)malloc(sizeof(int)*ptr_q->size);
  
}
  int qinsert(int x, queue_t *ptr_q)
  {
     //check if the queue is full;
	 
	 if(ptr_q->r==ptr_q->size-1)
	 {
		 printf("Queue full.. Cannot insert.\n");
		 return -1;
	 }
	 
	 ptr_q->r++;  // increment rear
	 ptr_q->item[ptr_q->r]=x;
	 if(ptr_q->f==-1)
	 		 ptr_q->f=0;  // if first element
	 return 1;
  }
	 
	 int qdelete(struct queue *p)
	 {
	   int x;
	   //check if queue is empty
	   
	   if(p->f==-1)
	   {
		   printf("Queue empty..\n");
	       return -1;
	   }
	   
	   x=p->item[p->f];
	   if(p->f==p->r)//only one element
	      p->f=p->r=-1;
	else
	     p->f++; // increment front after deletion
	 return x;
	 }
	 
	 void display(struct queue p)
	 {
		 
		 int i;
		 if(p.f==-1)
			 printf("Empty Queue...\n");
		 else
		 {
			 for(i=p.f;i<=p.r;i++)
				 printf("%d ",p.item[i]);
		 }
	 }
	 
	*/	 
	 
	 
	 
    







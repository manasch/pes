
#include"cqueue.h"

 void init(queue_t *ptr_q)
 {
	printf("Enter the size...\n");
    scanf("%d",&ptr_q->size);
    ptr_q->f=ptr_q->r=-1;
    ptr_q->cq=(int*)malloc(sizeof(int)*(ptr_q->size));
 }	
	 
 int qinsert (queue_t *ptr_q, int key)
 {
	 if((ptr_q->r+1)%ptr_q->size==ptr_q->f)
	 {
		 printf("queue full.. cannot insert\n");
		 return -1;
	 }
	 ptr_q->r=(ptr_q->r+1)%ptr_q->size; //increment rear 
	 ptr_q->cq[ptr_q->r]=key; // insert the element
	 if(ptr_q->f==-1) //if first element
		 ptr_q->f=0;
	 return 1;
 }
 
 int qdelete(queue_t *ptr_q)
 {
	 int key;
	 if(ptr_q->f==-1)
	 {
		 printf("Empty queue..\n");
		 return -1;
	 }
	 key=ptr_q->cq[ptr_q->f];
	 if(ptr_q->f==ptr_q->r)//only one element
	    ptr_q->f=ptr_q->r=-1;
	 else
		 ptr_q->f=(ptr_q->f+1)%ptr_q->size;
	 return key;
 }
		 
	void display(queue_t* ptr_q)
	{
		int f,r,size;
		if(ptr_q->f==-1)
			printf("Queue empty..\n");
		 else
		 {
			 f=ptr_q->f;
			 r=ptr_q->r;
			 size=ptr_q->size;
			 while(f!=r)
			 {
				 printf("%d ",ptr_q->cq[f]);
				 f=(f+1)%size;
			 }
			printf("%d ",ptr_q->cq[f]);
		 }	
	}		 
			 
			 
				 
				 
				 
			 
			 
			 
			 
			 
			 
		
		
	 
		 
		 
	 
	 
 
 
 
	 
	 
	 
	 
	 
	 
	 
	 
 
 
 
 
 
 
 













  











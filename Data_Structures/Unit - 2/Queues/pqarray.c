#include<stdio.h>
#include<stdlib.h>
//program to implement  priority queue
struct element
{
  int pty;
  int data;
};

typedef struct element element_t;
void pqinsert(element_t *,int , int ,int*);
element_t pqdelete(element_t*,int*);
void qdisplay(element_t*,int);
int main()
{
  int k,ch,pty,x;
  element_t pq[100],temp;
  
    int count=0;
  while(1)
  {
    qdisplay(pq,count);
    printf("\n1..insert");
    printf("\n2..remove");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the priority..");
              
              scanf("%d",&pty);
              printf("Enter the value");
              scanf("%d",&x);
              pqinsert(pq,x,pty,&count);
              
               break;
      case 2:temp=pqdelete(pq,&count);
              if(temp.data>0)
              {
                printf("deleted element:- data=%d",temp.data);
                printf("   priority=%d\n",temp.pty);
               }
              break;
        case 4:exit(0); 
   }
  }
 }

  void pqinsert(element_t *pq, int data, int pty, int *count)
  {
	  int j;
	  element_t temp;
	  temp.data=data;
	  temp.pty=pty;
	  
	  j=*count-1;
	  
	  while((j>=0)&&(pq[j].pty > temp.pty))
	  {
		  pq[j+1]=pq[j];
		  j--;
	  }
	  pq[j+1]=temp;
	  (*count)++;
  }
  
  void qdisplay(element_t *pq, int count)
  {
	  int i;
	  if(count==0)
		  printf("Empty queue..\n");
	  else
	  {
		  for(i=0;i<count;i++)
			  printf("%d , %d\n",pq[i].data , pq[i].pty);
	  }
  }
	  
	  element_t pqdelete(element_t *pq, int *count)
	  {
		  int i;
		  element_t temp;
		  if(*count==0)
		  {
			  temp.data=-1;
			  temp.pty=-1;
		  }
		  else
		  {
			  temp=pq[0];
			  for(i=1;i<*count;i++)
				  pq[i-1]=pq[i];
			 (*count)--;
		  }
		  return temp;
	  }
				  
			  
			  
			  
		  
	 
		  
	  
	  
	  
	  
	  
	  
	  
	  


























        
   
















  /*void pqinsert(int x,int pty,struct pqueue *q,int *count)
  {
     int j;
     struct pqueue temp;
     temp.data=x;
     temp.pty=pty;
     
     j=*count-1;

     while((j>=0 )&& (q[j].pty > temp.pty))
     {
      q[j+1]=q[j];
      j--;
    }
    q[j+1]=temp;
    (*count)++;
    }
   
 
   struct pqueue pqdelete(struct pqueue *q,int *count)
  {
    struct pqueue t;
     int i;
     if(*count==0)
     {
       t.data=-1;
       t.pty=0;
     }
     else
      {
        t=q[0];
        for(i=1;i<*count;i++)
           q[i-1]=q[i];
        (*count)--;        
     }
    return t;
  }

  

  struct pqueue pqdelete(struct pqueue *q, int *count)
  {
    int i;
    struct pqueue t;
    if(count==0)
    {
     t.data=-1;
     t.pty=0;
     }
   else
    {
    t=q[0];
    for(i=1;i<(*count);i++)
      q[i-1]=q[i];
    (*count)--;
    }
    return t;
  }
   
  void pqinsert(int x,int pty,struct pqueue *q,int *count)
  {
    struct pqueue temp;
    int j;
    temp.data=x;
    temp.pty=pty;

    //q[count++]=temp;
    j=*count-1;

    while(j>=0 && (q[j].pty > temp.pty))
    {
        q[j+1]=q[j];
        j--;
    }
     q[j+1]=temp;
     (*count)++;
  } 
    
     
  
   }
  }
*/
    
   
   





























   


   

   
  
    
    




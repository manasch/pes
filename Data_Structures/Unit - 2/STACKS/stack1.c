#include<stdio.h>
#include<stdlib.h>
void push(int*,int*,int,int);
int pop(int*,int*);
void display(int*,int);
int main()
{
  int top,size,ch,k,x;
  int *s;
  printf("Enter the size of the stack..\n");
  scanf("%d",&size);
  s=(int*)malloc(sizeof(int)*size);
  top=-1;
  while(1)
  {
    display(s,top);
    printf("\n1..push\n");
    printf("2..pop\n");
    printf("3..display\n");
    scanf("%d",&ch);
    switch(ch)
    {                                
 	case 1:printf("Enter the data\n");
             scanf("%d",&x);
             push(s,&top,size,x);
             break;
     case 2:k=pop(s,&top);
            if(k>0)
               printf("\nElement popped=%d\n",k);
            break;
     case 3:display(s,top);
            break;
     case 4:exit(0);
   }
 }
}

 void push(int *s, int *t,int size, int x)
 {
	 if(*t==size-1)
		 printf("\nstack overflow..");
	 else
	 {
		 (*t)++;//++*t or *t=*t+1
		 s[*t]=x;
	 }
 }
	
int pop(int *s, int *t)
{
	int key;
	if(*t==-1)
	{
		printf("\nstack underflow..\n");
	    return -1;
	}
	key=s[*t];
	(*t)--;//--*t or *t=*t-1
	return key;
}

  void display(int *s, int t)
  {
	  int i;
	  if(t==-1)
		  printf("\nEmpty stack..\n");
	  else
	  {
	    for(i=t;i>=0;i--)
	       printf("%d ",s[i]);
	  }
  }
		 
		 



















   
 


  



   

    






   

   

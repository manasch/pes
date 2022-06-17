
#include"cqueue.h"

int main()
{
  
   int ch,k,x;
   queue_t q;
   init(&q);
  while(1)
  {
    display(&q);
    printf("\n1..Insert");
    printf("\n2..Delete");
    printf("\n3..Display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              k=qinsert(&q,x);
              if(k>=0)
                 printf("Element inserted successfully\n");
               break;
       case 2:k=qdelete(&q);
              if(k>=0)
                printf("element deleted=%d\n",k);
              break;
		case 3:display(&q);
					  break;
        case 4:exit(0); 
   }
  }
 }

 
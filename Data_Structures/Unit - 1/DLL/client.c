#include "dll.h"
int main()
{
	int ch,key,pos;
	dlist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.delete first node");
		printf("\n5.Delete last node");
		printf("\n6.Delete Node");
		printf("\n7.Delete Node at position");
		printf("\n8.count using recursion");
		printf("\n9.reverse a list..\n");
		printf("\n10..Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_head(&l,key);
						 break;
		case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_tail(&l,key);
						 break;			 
		  case 3:display(&l);
			             break;
		case 4:delete_first(&l);
              			break;		
		case 5:delete_last(&l);
              			break;				
		case 6:printf("\nEnter the key...");
			             scanf("%d",&key);
						 delete_node(&l,key);	
                         break;	
		case 7:printf("\nEnter the position");
			             scanf("%d" ,&pos);
						 delete_pos(&l,pos);
						 break;	
		case 8:printf("\nEnter the key and position");
			             scanf("%d  %d" ,&key, &pos);
						 insert_pos(&l,key,pos);
						 break;	
           /* case 7 : display_reverse(&l);
			              break;	
            case 8:printf("The no of nodes = %d\n",count_nodes(&l));
                        break;		
           case 9 : reverse_list(&l);	
                         break;		*/   
			case 10:exit(0);
		}
	}
}
						 
			
			
			
			
#include "clist.h"
int main()
{
	int ch,key,pos;
	clist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.Delete a node");
		printf("\n5..Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_front(&l,key);
						 break;
			case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_end(&l,key);
						 break;			 
			case 3:display(&l);
			             break;
			 
			case 4:printf("\nEnter the key...");
			             scanf("%d",&key);
						 delete_node(&l,key);	
                         break;	
					   
			case 5:exit(0);
		}
	}
}
						 
			
			
			
			
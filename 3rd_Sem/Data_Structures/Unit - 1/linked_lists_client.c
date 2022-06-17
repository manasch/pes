#include<stdio.h>
#include"list_1.h"

int main()
{
    list_t l;
    init_list(&l);
    int choice;
    int key;

    while (1)
    {
        //display(&l);
        printf("\n\n1. Insert Front\n2. Insert End\n3. Insert at Position\n"\
                "4. Display\n5. Display reverse\n6. Count Nodes\n7. Reverse the list\n8. Delete a node\n9. Delete node by Pos\n10. Exit\n\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the key: ");
            scanf("%d", &key);
            insert_front(&l, key);
            break;

        case 2:
            printf("\nEnter the key: ");
            scanf("%d", &key);
            insert_end(&l, key);
            break;
        
        case 3:
            printf("\nEnter the position: ");
            int pos;
            scanf("%d", &pos);
            printf("\nEnter the key: ");
            scanf("%d", &key);
            insert_pos(&l, key, pos);
            break;
        
        case 4:
            printf("\nElements of the list:\n");
            display(&l);
            break;
        
        case 5:
            printf("\nReverse:\n");
            display_reverse(&l);
            break;

        case 6:
            printf("\nThe number of nodes = %d\n", count_nodes(&l));
            break;

        case 7:
            reverse(&l);
            printf("\nThe list has been reversed:\n");
            display(&l);
            break;

        case 8:
            printf("\nEnter the number to delete: ");
            scanf("%d", &key);
            delete(&l, key);
            break;

        case 9:
            printf("\nEnter the position to delete: ");
            int p;
            scanf("%d", &p);
            delete_pos(&l, p);
            break;

        case 10:
            exit(0);

        default:
            printf("\nInvalid input");
            break;
        }
    }
    
    
}
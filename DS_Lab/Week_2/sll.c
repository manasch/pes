#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *link;
}node_t;


typedef struct lis
{
    node_t *head;
}list_t;

void init(list_t *);
void swap(list_t *, int, int);
void delalt(list_t *);
void display(list_t *);
void insert(list_t *, int);


int main()
{
    int choice;
    int ele;
    int a, b;
    
    
    list_t l;
    
    init(&l);
    
    while(1)
    {
    printf("\n\n1. Insert\n2. Display\n3. Swap\n4. Delete Alt\n5. Exit\nChoice: ");
    scanf("%d", &choice);
    switch(choice)
        {
            case 1:
                printf("\nEnter key: ");
                scanf("%d", &ele);
                insert(&l, ele);
                break;
            case 2:
                display(&l);
                break;
            case 3:
                printf("\nEnter elements to swap: ");
                scanf("%d %d", &a, &b);
                swap(&l, a, b);
                break;
            case 4:
                delalt(&l);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid");
                break;
        }
    }
           
}


void init(list_t *l)
{
	l->head = NULL;
}

void insert(list_t *l, int k)
{
    node_t *temp, *pres;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->key = k;
    temp->link = NULL;

    if(l->head == NULL)
        l->head = temp;
    else
    {
        pres = l->head;
        while(pres->link != NULL)
            pres = pres->link;
        
        pres->link = temp;
    }
}


void display(list_t *l)
{
    node_t *pres;

    if(l->head == NULL)
        printf("\nEmpty List....");
    else
    {
        pres = l->head;
        printf("\n");
        while(pres != NULL)
        {
            printf("%d->", pres->key);
            pres = pres->link;
        }
    }
}


/*There will be 4 different cases
    1) swapping adjacent nodes
    2) swapping edge nodes
    3) swapping edge and middle nodes
    4) swapping non adjacent nodes
    5) input given doesn't match with the given 
*/
void swap(list_t *l, int a, int b)
{
    node_t *pres_1 = l->head, *pres_2 = l->head;
    node_t *prev_1 = NULL, *prev_2 = NULL;

    if(a == b)
    {
        return;
    }

    while(pres_1 != NULL && pres_1->key != a)
    {
        prev_1 = pres_1;
        pres_1 = pres_1->link;
    }
    
    while(pres_2 != NULL && pres_2->key != b)
    {
        prev_2 = pres_2;
        pres_2 = pres_2->link;
    }
    
    if(pres_1 == NULL || pres_2 == NULL)
    {
        return;
    }
    
    node_t *temp;

    if(prev_1 != NULL)
    {
        prev_1->link = pres_2;
    }
    else
    {
        l->head = pres_2;
    }

    if(prev_2 != NULL)
    {
        prev_2->link = pres_1;
    }
    else
    {
        l->head = pres_1;
    }
    
    temp = pres_2->link;
    pres_2->link = pres_1->link;
    pres_1->link = temp;

}

void delalt(list_t *l)
{
	node_t *pres, *next;
    next = NULL;

    if(l->head == NULL)
        return;
    else{
        pres = l->head;
        next = pres->link;
        while(pres != NULL && next != NULL)
        {
            pres->link = next->link;
            free(next);
            pres = pres->link;

            if(pres != NULL)
                next = pres->link;
        }
    }	
}
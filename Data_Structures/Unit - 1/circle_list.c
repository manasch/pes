// 14-9-2021

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node_t;

void insert_head(node_t *, int);
void insert_tail(node_t *, int);
void display(node_t *);
node_t *create_head();
void delete_node(node_t *, int);

int main()
{
    node_t *head;
    int x, ch;
    head = create_head(); //different implenetation of circular list, the head is part of the circular linked list

    while(1)
    {
        printf("\n");
        display(head);
        printf("\n1) Insert Head");
        printf("\n2) Insert Tail");
        printf("\n3) Display");
        printf("\n4) Delete a node");
        printf("\n5) Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the number: ");
            scanf("%d", &x);
            insert_head(head, x);
            break;
        
        case 2:
            printf("\nEnter the number: ");
            scanf("%d", &x);
            insert_tail(head, x);
            break;
        
        case 3:
            printf("\nNodes: ");
            display(head);
            break;
        
        case 4:
            printf("\nEnter the number: ");
            scanf("%d", &x);
            delete_node(head, x);
            break;

        case 5:
            exit(0);
        
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
}

node_t *create_head()
{
    node_t *temp;
    temp = (node_t *)malloc(sizeof(node_t));
    temp->data = 0;
    temp->next = temp;
    return temp;
}

void insert_head(node_t *p, int x)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
    p->data++; // header's data stores the number of nodes present in the linked list
}

void insert_tail(node_t *p, int x)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    node_t *q;
    temp->data = x;

    q = p->next;

    while(q->next != p)
        q = q->next;
    
    temp->next = q->next; // temp->next = p 
    q->next = temp;
    p->data++;
}

void delete_node(node_t *p, int x)
{
    node_t *prev, *q;

    q = p->next;
    prev = p;

    while((q != p) && (q->data != x))
    {
        prev = q;
        q = q->next;
    }

    if(q->data == x)
    {
        prev->next = q->next;
        free(q);
        p->data--;
    }
    else
    {
        printf("\nNode not found..");
    }
}

void display(node_t *p)
{
    node_t *pres;

    printf("%d: ", p->data);
    pres = p->next;
    while(pres != p)
    {
        printf("%d->", pres->data);
        pres = pres->next;
    }
}
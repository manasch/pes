#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char *name;
    int ph_no;
    char *address;
    char *area;
    struct node *next, *prev;
} Node;

typedef struct CustomerDetails
{
    Node *head;
} Cust_Details;

void init(Cust_Details *);
void display(Cust_Details *);
void insert(Cust_Details *, char *, int, char *, char *);
void sort(Cust_Details *);

int main()
{
    Cust_Details c;
    init(&c);
    int ph;
    char name[100], address[100], area[100];

    int ch;
    while(1)
    {
        printf("\n1) Insert Customer Details");
        printf("\n2) Display Customer Details");
        printf("\n3) Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Name, Ph No, Address, Area: ");
            scanf("%s %d %s %s", name, &ph, address, area);
            insert(&c, name, ph, address, area);
            break;

        case 2:
            display(&c);
            break;

        case 3:
            exit(0);
        
        default:
            printf("\nInvalid Input..");
            break;
        }
    }
}

void init(Cust_Details *c)
{
    c->head = NULL;
}

void insert(Cust_Details *c, char *name, int ph, char *address, char *area)
{
    Node *temp, *pres;

    temp = (Node *)malloc(sizeof(Node));

    temp->next = temp->prev = NULL;
    temp->ph_no = ph;
    
    temp->name = (char *)malloc(sizeof(name));
    strcpy(temp->name, name);
    
    temp->address = (char *)malloc(sizeof(address));
    strcpy(temp->address, address);
    
    temp->area = (char *)malloc(sizeof(area));
    strcpy(temp->area, area);
    
    if (c->head == NULL)
        c->head = temp;
    
    else if (strcmp(c->head->name, temp->name) >= 0)
    {
        temp->next = c->head;
        temp->next->prev = temp;
        c->head = temp;
    }

    else
    {
        pres = c->head;

        while(pres->next != NULL && strcmp(pres->next->name, temp->name) < 0)
            pres = pres->next;

        temp->next = pres->next;

        if(pres->next != NULL)
            temp->next->prev = temp;
        
        pres->next = temp;
        temp->prev = pres;
    }
}

void display(Cust_Details *c)
{
    Node *pres;

    pres = c->head;
    if(pres == NULL)
        printf("\nEmpty list...");
    while(pres != NULL)
    {
        printf("(%s, %d, %s, %s) <=> ", pres->name, pres->ph_no, pres->address, pres->area);
        pres = pres->next;
    }
}

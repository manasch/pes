#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define NAME_LENGTH 20

typedef struct node
{
    long int ph;
    char name[NAME_LENGTH];
    struct node *next;
} node;

typedef struct hash
{
    node *head;
    int count;
} hash;

void init(hash *);
void insert(hash *, char *, long int);
void display(hash *);
int search(hash *, long int);
int delete(hash *, long int);

int main()
{
	hash hashtable[MAX];
    int choice;
    long int ph;
    int res;
    char name[NAME_LENGTH];
    
    init(hashtable);


    while (1)
    {
        printf("\n1) Insert\n2) Display\n3) Delete\n4) Search\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter name: ");
            scanf("%s", name);
            printf("\nEnter phone number: ");
            scanf("%ld", &ph);
            
            insert(hashtable, name, ph);
            break;
        
        case 2:
            display(hashtable);
            break;
        
        case 3:
            printf("\nEnter phone number to be deleted: ");
            scanf("%ld", &ph);
            res = delete(hashtable, ph);

            if (res)
                printf("\nPhone record has been deleted");
            else
                printf("\nPhone record does not exist in hashtable");
            break;
        
        case 4:
            printf("\nEnter phone number to be searched: ");
            scanf("%ld", &ph);
            res = search(hashtable, ph);

            if (res)
                printf("\n%ld exists in hashtable", ph);
            else
                printf("\n%ld does not exist in hashtable", ph);
            break;
        
        default:
            printf("\nInvalid choice");
            break;
        }
    }
}

void init(hash *ht)
{
    for (int i = 0; i < MAX; i++)
    {
        ht[i].head = NULL;
        ht[i].count = 0;
    }
}

void insert(hash *ht, char *name, long int ph)
{
    int index;
    index = ph % MAX;

    node *temp = (node *) malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->ph = ph;

    temp->next = ht[index].head;
    ht[index].head = temp;
    ht[index].count++;
}

void display(hash *ht)
{
    node *temp;
    printf("\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d: ", i);
        if (ht[i].head != NULL)
        {
            temp = ht[i].head;
            while (temp != NULL)
            {
                printf("[%s; %ld] -> ", temp->name, temp->ph);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

int search(hash *ht, long int ph)
{
    int index = ph % MAX;

    if (ht[index].head != NULL)
    {
        node *temp;
        temp = ht[index].head;
        while (temp != NULL && temp->ph != ph)
            temp = temp->next;
        
        if (temp == NULL)
            return 0;
        else
            return 1;
    }
}

int delete(hash *ht, long int ph)
{
    int index = ph % MAX;
    node *pres, *prev;
    pres = ht[index].head;
    prev = NULL;

    while (pres != NULL && pres->ph != ph)
    {
        prev = pres;
        pres = pres->next;
    }

    if (pres != NULL)
    {
        if (prev == NULL)
            ht[index].head = pres->next;
        else
            prev->next = pres->next;
        
        free(pres);
        return 1;
    }
    else
        return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define NAME_LENGTH 20

typedef struct node
{
    long int ph;
    char name[NAME_LENGTH];
    int mark;
} node;

void init(node *);
void insert(node *, char *, long int, int *);
void display(node *);
int search(node *, long int);
int delete(node *, long int, int *);

int main()
{
	node hashtable[MAX];
    int choice;
    long int ph;
    int res;
    char name[NAME_LENGTH];
    int ele_count = 0;
    
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
            
            insert(hashtable, name, ph, &ele_count);
            break;
        
        case 2:
            display(hashtable);
            break;
        
        case 3:
            printf("\nEnter phone number to be deleted: ");
            scanf("%ld", &ph);
            res = delete(hashtable, ph, &ele_count);

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

void init(node *ht)
{
    for (int i = 0; i < MAX; i++)
    {
        ht[i].mark = 0;
    }
}

void insert(node *ht, char *name, long int ph, int *count)
{
    if (*count >= MAX)
    {
        printf("\nHashtable is full");
        return;
    }

    int index = ph % MAX;
    int i = 0;

    while (i < MAX && ht[index].mark != 0)
    {
        index = (index + 1) % MAX;
        i++;
    }

    if (i < MAX)
    {
        strcpy(ht[index].name, name);
        ht[index].ph = ph;
        ht[index].mark = 1;
        *(count)++;

        printf("\nThe element has been inserted");
    }
    else
        printf("\nThe element was not inserted");
}

void display(node *ht)
{
    printf("\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d: ", i);
        if (ht[i].mark == 1)
        {
            printf("[%s; %ld]", ht[i].name, ht[i].ph);
        }
        printf("\n");
    }
    
}

int search(node *ht, long int ph)
{
    int index = ph % MAX;
    int i = 0;

    while (i < MAX && ht[index].ph != ph)
    {
        index = (index + 1) % MAX;
        i++;
    }

    if (i < MAX && ht[index].mark != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int delete(node *ht, long int ph, int *count)
{
    int index = ph % MAX;
    int i = 0;

    while (i < MAX && ht[index].ph != ph)
    {
        index = (index + 1) % MAX;
        i++;
    }

    if (i < MAX && ht[index].mark)
    {
        ht[index].mark = 0;
        *(count)--;
        return 1;
    }
    else
        return 0;
}
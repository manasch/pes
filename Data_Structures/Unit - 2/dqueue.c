#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
} node_t;


typedef struct dqueue
{
    node_t *front;
    node_t *rear;
} dqueue_t;

void init();

void insert_front(dqueue_t *p, int key)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->key = key;
    temp->next = NULL;

    if (p->front == NULL) // first element
    {
        p->front = p->front = temp;
    }
    else
    {
        temp->next = p->front;
        p->front = temp;
    }
}

int delete_front(dqueue_t *p)
{
    if (p->front == NULL)
    {
        printf("\nEmpty Queue");
        return -1;
    }
    node_t *pres;
    pres = p->front;
    int key = pres->key;

    if (p->front == p->rear) // one node
    {
        p->front = p->rear = NULL;
    }
    else
    {
        p->front = pres->next;
    }
    free(pres);
    return key;
}

int delete_rear(dqueue_t *p)
{
    if (p->front == NULL)
    {
        printf("\nEmpty Queue");
        return -1;
    }
    node_t *pres, *prev;
    pres = p->front;
    int key = pres->key;

    while (pres != p->rear) // go to the last node
    {
        prev = pres;
        pres = pres->next;
    }

    key = pres->key;
    if (prev == NULL)
    {
        p->front = p->rear = NULL;
    }
    else
    {
        prev->next = NULL;
        p->rear = prev;
    }

    free(pres);
    return key;
}
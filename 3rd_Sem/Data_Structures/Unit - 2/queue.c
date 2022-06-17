#include<stdio.h>

typedef struct queue
{
    int *r, *f;
    int size;
    int item[10];
} queue_t;

void init(queue_t *ptr_q)
{
    printf("\nEnter the max size of the queue: ");
    scanf("%d", &ptr_q->size);
}


int main()
{
    
}


int qinsert(queue_t *ptr_q, int key)
{
    if (ptr_q->r == ptr_q->size-1)
    {
        printf("\nQueue is full");
        return -1;
    }

    ptr_q->r++; // increament rear
    ptr_q->item[*(ptr_q->r)];
}

int qdelete(queue_t *ptr_q)
{
    int key;
    if (ptr_q->f == -1)
    {
        printf("\nEmpty queue");
        return -1;
    }

    key = ptr_q->item[*(ptr_q->f)];
    if (ptr_q->f == ptr_q->r)
        ptr_q->f = ptr_q->r = -1;
    else
        ptr_q->f++; //increament front
    
    return key;
}
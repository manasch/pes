#include<stdio.h>


typedef struct circularq
{
    int f, r;
    int size;
    struct circularq *cq;
} queue_t;


void init(queue_t *ptr_q)
{
    // ptr_q->cq
}

void qinsert(queue_t *ptr_q, int key)
{
    // r = (r + 1) % size
    // to check for overflow
    // if ((r + 1) % size) == f)

    if ((ptr_q->r + 1) % ptr_q->size == ptr_q->f)
    {
        printf("\nQueue is full");
        return -1;
    }
    ptr_q->r = (ptr_q->r + 1) % ptr_q->size;
    ptr_q->cq[ptr_q->r] = key;
    if(ptr_q->f == -1) // first elements
        ptr_q->f = 0;
    return 1;
}

int qdelete(queue_t *ptr_q)
{
    if (ptr_q->f == -1)
    {
        printf("\nQueue is empty")
        return -1
    }
    int key = ptr_q->cq[ptr_q->f];
    if (ptr_q->f == ptr_q->r) // only one element
        ptr_q->f = ptr_q->r = -1;
    else
        ptr_q->f = (ptr_q->f + 1) % ptr_q->size
    
    return key;
}

void display(queue_t *ptr_q)
{
    int f, size, r;
    f = ptr_q->f;
    r = ptr_q->r;
    size = ptr_q->size;

    while (f != r)
    {
        printf("%d ", ptr_q->cq[f])
        f = (f + 1) % size;
    }
    printf("%d ", ptr_q->cq[f]) // last element
    
}
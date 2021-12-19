#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int *cq;
	int f,r,size;
} queue_t;

void init(queue_t *);
int qinsert(queue_t *, int);
int qdelete(queue_t *);
void display(queue_t *);
int qisempty(queue_t *);

int main()
{
    int ch, k, n;
    int p[100], i;
    queue_t q;
    init(&q);
    printf("Enter the number of persons: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        qinsert(&q, i);
    }
    
    while (!qisempty(&q))
    {
        k = qdelete(&q);
        qinsert(&q, k);
        k = qdelete(&q);
    } // k will have the last deleted element

    printf("\nWinner = %d", k);
}

int qisempty(queue_t *q)
{
    if (q->f == -1)
        return 1;
    return 0;
}


void init(queue_t *ptr_q)
{
    // printf("Enter the size: \n");
    //scanf("%d", &ptr_q->size);
    ptr_q->size=100;
    ptr_q->f = ptr_q->r =- 1;
    ptr_q->cq = (int *)malloc(sizeof(int) * (ptr_q->size));
}

int qinsert(queue_t *ptr_q, int key)
{
    if((ptr_q->r + 1) % ptr_q->size == ptr_q->f)
    {
        printf("Queue is full\n");
        return -1;
    }
    ptr_q->r = (ptr_q->r + 1) % ptr_q->size; //increment rear 
    ptr_q->cq[ptr_q->r] = key; // insert the element
    if(ptr_q->f == -1) //if first element
        ptr_q->f = 0;
    return 1;
}
 
int qdelete(queue_t *ptr_q)
{
    int key;
    if(ptr_q->f == -1)
    {
        printf("Empty queue\n");
        return -1;
    }
    key = ptr_q->cq[ptr_q->f];
    if(ptr_q->f == ptr_q->r)//only one element
    ptr_q->f = ptr_q->r =- 1;
    else
        ptr_q->f = (ptr_q->f + 1) % ptr_q->size;
    return key;
}

void display(queue_t* ptr_q)
{
    int f, r, size;
    if(ptr_q->f == -1)
        printf("Queue empty\n");
    else
    {
        f = ptr_q->f;
        r = ptr_q->r;
        size = ptr_q->size;
        while(f != r)
        {
            printf("%d ", ptr_q->cq[f]);
            f = (f + 1) % size;
        }
        printf("%d ", ptr_q->cq[f]);
    }	
}
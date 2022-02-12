#include<stdlib.h>
#include<stdio.h>
struct queue
{
	int *item;
	int f;
	int r;
	int size;
};
typedef struct queue queue_t;

void init(queue_t*);
int  qinsert(queue_t *,int);
int qdelete(queue_t*);
void display(queue_t*);








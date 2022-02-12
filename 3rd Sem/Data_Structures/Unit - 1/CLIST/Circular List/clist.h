#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	 struct node *link;
};

typedef struct node node_t;

struct list
{
	node_t *last;
};

typedef struct list clist_t;

void init_list(clist_t *);
void insert_front(clist_t *, int);
void insert_end(clist_t*,int);
void delete_node(clist_t*, int);
void display(clist_t*);










	
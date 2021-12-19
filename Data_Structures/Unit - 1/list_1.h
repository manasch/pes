#include<stdio.h>
#include<stdlib.h>

// THe node contains the data and the address to the next node
struct node
{
    int key;
    struct node *link;
};

typedef struct node node_t;

struct list
{
    node_t *head;
    node_t *tail;
};

typedef struct list list_t;

void init_list(list_t *);
void insert_front(list_t *, int);
void insert_end(list_t *, int);
void display(list_t *);
void insert_pos(list_t *, int, int);
void display_reverse(list_t *);
void display_nodes(node_t *);
int count_nodes(list_t *);
int count_node_recur(node_t *);
void reverse(list_t *);
void delete(list_t *, int);
void delete_pos(list_t *, int);
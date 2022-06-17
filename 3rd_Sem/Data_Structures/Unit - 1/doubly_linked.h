#include<stdio.h>
#include<stdlib.h>

typedef struct dnode
{
    d_node *prev;
    int key;
    d_node *next;
} d_node;

typedef struct dlist
{
    d_node *head;
} d_list;
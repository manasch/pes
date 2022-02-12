#include<stdio.h>
#include"circular_linked_list.h"


// address of the last node is stored in the structure

void init_list(list_t *ptr_list)
{
    ptr_list->last = NULL;
}

void insert_front(list_t *ptr_list, int key)
{
    node_t *temp;
    temp = (node_t *)malloc(sizeof(node_t));
    temp->key = key;
    temp->link = temp;

    node_t *last;
    last = ptr_list->last;

    // if(ptr_list->last == NULL)
    if(last == NULL)
        ptr_list->last = temp;
    else
    {
        temp->link = last->link;
        ptr_list->last->link = temp;
    }
}

void insert_end(list_t *ptr_list, int key)
{
    node_t *temp;
    temp = (node_t *)malloc(sizeof(node_t));
    temp->key = key;
    temp->link = temp;

    node_t *last;
    last = ptr_list->last;

    if(ptr_list->last == NULL)
        ptr_list->last = temp;
    else
    {
        temp->link = last->link;
        last->link = temp;
        ptr_list->last = temp;
    }
}

void display(list_t *ptr_list)
{

}

void delete(list_t *ptr_list)
{
    
}
#include<stdio.h>
#include"circular_linked_list.h"


// USING DOUBLE POINTERS IN THIS

// address of the last node is stored in the structure

void init_list(node_t **ptr_list)
{
    *ptr_list = NULL;
}

void insert_front(node_t **ptr_list, int key)
{
    node_t *temp, *last;

    temp = (node_t *)malloc(sizeof(node_t));
    temp->key = key;
    temp->link = temp;

    // last = *ptr_list;

    if(*ptr_list == NULL)
        *ptr_list = temp;
    else
    {
        temp->link = (*ptr_list)->link;
        (*ptr_list)->link = temp;
    }
}

// void insert_end(node_t *ptr_list, int key)
// {
//     node_t *temp;
//     temp = (node_t *)malloc(sizeof(node_t));
//     temp->key = key;
//     temp->link = temp;

//     node_t *last;
//     last = ptr_list->last;

//     if(ptr_list->last == NULL)
//         ptr_list->last = temp;
//     else
//     {
//         temp->link = last->link;
//         last->link = temp;
//         ptr_list->last = temp;
//     }
// }

void display(node_t *ptr_list)
{

}

void delete(node_t *ptr_list)
{
    
}
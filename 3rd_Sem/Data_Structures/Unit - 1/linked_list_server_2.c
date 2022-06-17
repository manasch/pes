#include<stdio.h>
#include"list_1.h"

void init_list(list_t *list_ptr)
{
    list_ptr->head = NULL;
    //modify the program to add a tail to make insert_end faster
}

void insert_front(list_t *list_ptr, int key)
{
    node_t *temp;
    //Create and populate the node in a temporary node
    temp = (node_t*)malloc(sizeof(node_t));
    temp->key = key;
    temp->link = NULL;

    //Condition for empty list has to be checked

    if(list_ptr->head == NULL)
        list_ptr->head = temp;
    //list is not empty
    else
    {
        temp->link = list_ptr->head;
        list_ptr->head = temp;
    }
}

void insert_end(list_t *list_ptr, int key)
{
    node_t *temp, *pres;
    //Create and populate the node in a temporary node
    temp = (node_t*)malloc(sizeof(node_t));
    temp->key = key;
    temp->link = NULL;

    if(list_ptr->head == NULL)
        list_ptr->head = temp;
    else
    //go to the last node
    {
        pres = list_ptr->head;
        while(pres->link != NULL)
            pres = pres->link;
        
        pres->link = temp;
    }
}

void insert_pos(list_t *list_ptr, int key, int pos)
{
    node_t *temp, *pres, *prev;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->key = key;
    temp->link = NULL;

    prev = NULL;
    pres = list_ptr->head;

    int counter = 1;

    //until the position is found, go forward or go beyond the last node
    while((pres != NULL) && (counter < pos))
    {
        prev = pres;
        pres = pres->link;
        counter++;
    }
    //position is found

    if(pres != NULL)
    {
        if(prev == NULL)//first position
        {
            temp->link = pres;
            list_ptr->head = temp;
        }
        else//2nd position to last but one
        {
            prev->link = temp;
            temp->link = pres;
        }
    }
    else
    {
        if(counter == pos) // last position
            prev->link = temp;
        else
            printf("\nInvalid Position");
    }
}

void display(list_t *list_ptr)
{
    node_t *present;
    if(list_ptr->head == NULL)
        printf("\nEmpty List");
    else
    {
        present = list_ptr->head;
        while (present != NULL)
        {
            printf("%d->", present->key);
            present = present->link;
        }
    }
}

void display_reverse(list_t *list_ptr)
{
    display_nodes(list_ptr->head);
}

void display_nodes(node_t *pres)
{
    if(pres->link != NULL)
        display_nodes(pres->link);
    printf("%d->", pres->key);
}

int count_nodes(list_t *list_ptr)
{
    if (list_ptr->head == NULL)
        return 0;
    else
        return count_node_recur(list_ptr->head);
}

int count_node_recur(node_t *pres)
{
    if(pres->link == NULL)
        return 1;
    return (1 + count_node_recur(pres->link));
}

void reverse(list_t *list_ptr)
{
    node_t *pres, *prev, *temp;
    pres = list_ptr->head;
    prev = NULL;

    while(pres != NULL)
    {
        temp = pres->link;
        pres->link = prev;
        prev = pres;
        pres = temp;
    }
    list_ptr->head = prev;
}

void delete(list_t *list_ptr, int key)
{
    node_t *prev, *pres;

    prev = NULL;
    pres = list_ptr->head;

    //traverse the list
    //or you go beyond the list
    while((pres->key != key) && (pres != NULL))
    {
        prev = pres;
        pres = pres->link;
    }
    if(pres != NULL) //node is found
    {
        //if first node
        if(prev == NULL)
            list_ptr->head = pres->link;
        else
            prev->link = pres->link;
        free(pres);
        pres->link = NULL;
    }
    else
        printf("\nNode not found...\n");
}

void delete_pos(list_t *list_ptr, int pos)
{
    node_t *prev, *pres;

    prev = NULL;
    pres = list_ptr->head;

    int i = 1;

    //traverse the list till the position is found

    while((pres != NULL) && (i < pos))
    {
        prev = pres;
        pres = pres->link;
        i++;
    }

    if(pres != NULL) // position is found
    {
        if(prev == NULL)
            list_ptr->head = pres->link;
        else
            prev->link = pres->link; // middle or last
    }
    else
        printf("\nInvalid Position");
    
    free(pres);
    pres->link = NULL;
}
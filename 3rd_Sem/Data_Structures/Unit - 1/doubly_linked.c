#include<stdio.h>
#include"doubly_linked.h"

void init(d_list *d)
{
    d->head = NULL;
}

void insert_head(d_list *ptr_list, int key)
{
    d_node *temp;

    temp = (d_node *)malloc(sizeof(d_node));
    temp->key = key;
    temp->next = temp->prev = NULL;

    //if list empty

    if(ptr_list->head == NULL)
        ptr_list->head = temp;
    else
    {
        temp->next = ptr_list->head;
        ptr_list->head->prev = temp;
        ptr_list->head = temp;
    }
    // code might not be correct
}

void delete_first(d_list *ptr_list)
{
    d_node *pres;

    pres = ptr_list->head;

    // If only one node present
    if (pres->next == NULL)
        ptr_list->head = NULL;
    else
    {
        pres->next->prev = NULL;
        ptr_list->head = pres->next;
    }
    free(pres);
}

void delete_last(d_list *ptr_list)
{
    d_node *pres;

    pres = ptr_list->head;

    if(pres->next == NULL)
        ptr_list->head = NULL;
    else
    {
        while(pres->next != NULL)
            pres = pres->next;
        
        pres->prev->next = NULL;
    }
    free(pres);
}

// Delete by key
/*
Node present
1) Only node present
2) First node
3) Second to last but one node
4) Last node
*/

void delete_node_key(d_list *ptr_list, int key)
{
    d_node *pres;

    pres = ptr_list->head;

    if(pres->next == NULL)
        ptr_list->head = NULL;
    else
    {
        while(pres->next != NULL && pres->key != key)
        {
            pres = pres->next;
        }
        
        if(pres != NULL) // Node is not found
        {
            //where is it found
            // perform the 4 checks

            /*
            if(pres->prev == NULL && pres->next == NULL) // The only node
                ptr_list->head = NULL*/

            if(pres->prev == NULL) // The first node // takes care if it is the first node or the only node
                ptr_list->head = pres->next;

            else if(pres->next == NULL) // The last nod
                pres->prev->next = NULL;

            else // The middle node
            {
                pres->prev->next = pres->next;
                pres->next->prev = pres->prev;
            }        
            free(pres);
        }
        else
            printf("Node not found..");

    }
}

void delete_node_pos(d_list *ptr_list, int pos)
{
    d_node *pres;
    pres = ptr_list->head;
    int count = 1;

    while(pres != NULL && count < pos)
    {
        pres = pres->next;
        count++;
    }
    // Fill the implementation
}

void insert_node_pos(d_list *ptr_list, int pos, int key)
{
    d_node *pres, *temp;
    int count = 1;

    temp = (d_node *)malloc(sizeof(d_node));

    temp->key = key;
    temp->next = temp->prev = NULL;

    pres = ptr_list->head;

    /*
    while(pres != NULL && count < pos)
    {
        pres = pres->next;
        count++;
    }
    */

    int i = 1;
    while(i < pos && pres->next != NULL)
    {
        pres = pres->next;
        i++;
    }

    if (i == pos) // node found
    {
        //first position
        if(pres->prev == NULL)
        {
            temp->next = pres;
            pres->prev = temp;
            ptr_list->head = temp;
        }
        else
        {
            pres->prev->next = temp;
            temp->prev = pres->prev;
            temp->next = pres;
            pres->prev = temp;
        }
    }
    else if(i == pos - 1) // inserting at the end
    {
        pres->next = temp;
        temp->prev = pres;
    }
    else
    {
        printf("\nInvalid position"); //Have to free the temp node
        free(temp);
    }
}

void insert_after_node(d_list *ptr_list, int key, int value_pos)
{
    d_node *temp = (d_node *)malloc(sizeof(d_node));
    d_node *pres;
    temp->key = key;
    temp->next = temp->prev = NULL;

    pres = ptr_list->head;

    while(pres->key != value_pos && pres->next != NULL)
        pres = pres->next;
    
    if(pres->key == value_pos)
    {
        if(pres->next != NULL) //insert somewhere between
        {
            temp->next = pres->next;
            temp->next->prev = temp;
            pres->next = temp;
            temp->prev = pres;
        }
        else //insert after the last node
        {
            pres->next = temp;
            temp->prev = pres;
        }
    }
    else
    {
        printf("\nNode with a given value %d not found..", value_pos);
        free(temp);
    }
}

void insert_before_node(d_list *ptr_list, int key, int value)
{
    d_node *temp, *pres;
    temp = (d_node *)malloc(sizeof(d_node));
    temp->key = key;
    temp->prev = temp->next = NULL;

    pres = ptr_list->head;

    while(pres->key != value && pres->next != NULL)
        pres = pres->next;

    if(pres->key == value)
    {
        if(pres->prev == NULL) //insert at the beginning
        {
            ptr_list->head = temp;
            temp->next = pres;
            pres->prev = temp;
        }
        else //insert anywhere else
        {
            pres->prev->next = temp;
            temp->prev = pres->prev;
            temp->next = pres;
            pres->prev = temp;
        }
    }
    else
    {
        printf("\nValue given is not found..");
        free(temp);
    }
}
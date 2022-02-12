#include<stdio.h>
#include<string.h>
#include"4.h"

void swap(student **ptr1, student **ptr2)
{
    student *temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void app(student **ptr, int n, void (*f)(student**, int))
{
    f(ptr, n);
}

void sort_roll(student **ptr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(ptr[j+1]->rno < ptr[j]->rno)
                swap(&ptr[j], &ptr[j+1]);
        }
    }
}

void sort_name(student **ptr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(strcmp(ptr[j]->name, ptr[j+1]->name) > 0)
                swap(&ptr[j], &ptr[j+1]);
        }
    }
}
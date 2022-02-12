// Implementation of priority queue, element can be inserted in any way, but during deletion the element with the highest priority gets deleted
// can be done with queues, linked list or heaps
#include<stdio.h>
#include<stdlib.h>

struct element
{
    int data;
    int pty; // priority
};

typedef struct element element_t;

int main()
{
    int data, pty;
    int count = 0;
    int choice;
    element_t temp;

    element_t pq[100]; // array of element structures

    while (1)
    {
        printf("\n1) Insert");
        printf("\n2) Delete");
        printf("\n3) Display");
        printf("\n4) Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data and priority: ");
            scanf("%d %d", &data, &pty);
            pqinsert(pq, pty, data, &count);
            break;
        
        case 2:
            temp = pqdelete(pq, &count);
            if (temp.pty == -1)
            {
                printf("\nQueue is empty");
            }
            else
            {
                printf("\n%d %d", temp.pty, temp.data);
            }
            break;
        
        case 3:
            display(pq, &count);
            break;
        
        case 4:
            exit(0);

        default:
            printf("\nInvalid Input");
            break;
        }
    }
    

}

void pqinsert(element_t *pq, int pty, int data, int *count)
{
    element_t temp;
    temp.data = data;
    temp.pty = pty;

    int j = *count - 1;
    while (j >= 0 && pq[j].pty > temp.pty)
    {
        pq[j + 1] = pq[j]; // structures can be copied by assignment operator, for array each element has to copied
        j--;
    }

    pq[j + 1] = temp; // handles botht the cases, beginning, middle or end
    (*count)++;
}

element_t pqdelete(element_t *pq, int *count)
{
    element_t temp;
    if (*count == 0)
    {
        temp.data = -1;
        temp.data = -1;
    }
    else
    {
        temp = pq[0];
        for (int i = 1; i < *count; i++)
        {
            pq[i - 1] = pq[i];
            (*count)--;
        }
        return temp;
    }
}

void display(element_t *pq, int *count)
{
    element_t *t = pq;
    int i = 0;
    while (i <= *count)
    {
        printf("(%d, %d) ", pq[i].pty, pq[i].data);
    }
}
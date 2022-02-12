// Implement a queue using an array with its appropriate boundary conditions (15 M)

#include <stdio.h>
#include <stdlib.h>

int enqueue(int *, int, int *, int *, int);
int dequeue(int *, int *, int *);
void display(int *, int, int);

int main()
{
    int n, ch, res, ele;
    int r = -1, f = -1; // front and rear
    printf("\nEnter the number of elements in queue: ");
    scanf("%d", &n);
    int queue[n];

    while (1)
    {
        printf("\n1) Enqueue");
        printf("\n2) Dequeue");
        printf("\n3) Display");
        printf("\n4) Exit");
        printf("\nChoice: ");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &ele);
            res = enqueue(queue, ele, &r, &f, n);
            if (res > 0)
                printf("\nElement inserted succesfully");
            break;
        
        case 2:
            res = dequeue(queue, &r, &f);
            if (res >= 0)
                printf("\nElement %d has been deleted", res);
            break;
        
        case 3:
            display(queue, r, f);
            break;
        
        case 4:
            exit(0);
        
        default:
            printf("\nInvalid Input");
            break;
        }
    }
}

int enqueue(int *q, int ele, int *r, int *f, int n)
{
    if (*r == n - 1)
    {
        printf("\nQueue Overflow");
        return -1;
    }
    
    (*r)++;
    q[*r] = ele;

    if (*f == -1)
        *f = 0;
    
    return 1;
}

int dequeue(int *q, int *r, int *f)
{
    if (*f == -1)
    {
        printf("\nQueue Underflow");
        return -1;
    }

    int temp;
    temp = q[*f];

    if (*f == *r)
        *f = *r = -1;
    else
        (*f)++;
    
    return temp;
}

void display(int *q, int r, int f)
{
    if (f == -1)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}
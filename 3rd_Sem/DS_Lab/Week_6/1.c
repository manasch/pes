// Implement queues using stacks

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void push(int *, int, int *);
int pop(int *, int *);
int enqueue(int *, int, int *);
int dequeue(int *, int *);
void display(int *, int *);


int main()
{
    int ch;
    int top = -1;
    int no;
    int res;
    int arr[MAX];

    while (1)
    {
        printf("\n1) Enqueue\n2) Dequeue\n3) Display\n4) Quit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter number to enqueue: ");
            scanf("%d", &no);
            
            res = enqueue(arr, no, &top);
            if (res)
                printf("\nEntered Successfully");
            else
                printf("\nNot entered");
            
            break;

        case 2:
            res = dequeue(arr, &top);
            if (res == -1)
                printf("\nEmpty Queue");
            else
                printf("\n%d exited the queue", res);
            break;
        
        case 3:
            display(arr, &top);
            break;
        
        case 4:
            exit(0);

        default:
            printf("\nInvalid Choice");
            break;
        }
    }   
}


void push(int *arr, int no, int *top)
{
    (*top)++;
    arr[*top] = no;
}

int pop(int *arr, int *top)
{
    int temp = arr[*top];
    (*top)--;
    return temp;
}

int enqueue(int *arr, int no, int *top)
{
    if (*top == MAX - 1)
    {
        printf("\nQueue Overflow");
        return 0;
    }

    push(arr, no, top);
    return 1;
}

int dequeue(int *arr, int *top)
{
    if (*top == -1)
        return -1;
    
    int z;
    int len;

    int *temp = (int *) malloc((*top + 1) * sizeof(int));
    int *ttop = (int *) malloc(sizeof(int));
    *ttop = -1;

    len = *top;
    // storing the number of elements in the main stack to pop into the temporary stack

    for (int i = 0; i < len; i++)
    {
        push(temp, pop(arr, top), ttop);
    }

    z = pop(arr, top);
    
    len = *ttop;
    // storing the number of elements in the temp stack to pop it back to the main stack

    for (int j = 0; j <= len; j++)
    {
        push(arr, pop(temp, ttop), top);
    }

    free(temp);
    free(ttop);

    return z;
}

void display(int *arr, int *top)
{
    if (*top == -1)
        printf("\nNothing to Display");
    else
    {
        printf("\nExit <-- ");
        for (int i = 0; i <= *top; i++)
            printf("%d ", arr[i]);
        printf("<-- Entry");
    }
}
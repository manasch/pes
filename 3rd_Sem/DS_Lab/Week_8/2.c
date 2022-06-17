// Write a program to implement heap in top_down approach, create min_heap

#include <stdio.h>
#include <stdlib.h>

void top_down(int *, int);
void display(int *, int);

int main()
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    
    int heap[n];
    
    printf("\nEnter the elements: ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }
    
    top_down(heap, n - 1);
    display(heap, n);
    
    return 0;
}

void top_down(int *h, int n) // n is the index of the last node
{
    int parent, child, key;
    
    for (int i = 1; i <= n; i++)
    {
        child = i;
        key = h[child];
        parent = (child - 1) / 2;
        
        while ((child > 0) && (key < h[parent]))
        {
            h[child] = h[parent];
            child = parent;
            parent = (child - 1) / 2;
        }
        h[child] = key;
    }
}

void display(int *h, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", h[i]);
    }
}

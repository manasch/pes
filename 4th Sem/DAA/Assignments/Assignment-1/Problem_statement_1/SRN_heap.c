// Name: Manas Chebrolu
// SRN: PES1UG20CS111
#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Function that will make sure that the array is a heap
// last is the index of the last element
// static void heapify(heap_t *heap, int last)
// {
//     int parent, child;
//     int key;

//     parent = 0; // root
//     child = (2 * parent) + 1; // left child
//     key = heap->arr[parent];

//     while (child <= last)
//     {
//         if (child + 1 <= last)
//         {
//             if (heap->arr[child + 1] > heap->arr[child])
//             {
//                 child++; // Right child
//             }
//         }
//         if (key < heap->arr[child])
//         {
//             heap->arr[parent] = heap->arr[child];
//             parent = child;
//             child = (2 * parent) + 1;
//         }
//         else
//             break;
//     }
//     heap->arr[parent] = key;
// }

// Function to create a heap in top down approach
static void top_down_heap(heap_t *heap, int last, int *count)
{
    int child, parent, k;
    int key;

    for (k = 1; k <= last; k++)
    {
        child = k;
        key = heap->arr[child];
        parent = (child - 1) / 2;

        while ((child > 0) && (key > heap->arr[parent]) && ++(*count))
        {
            heap->arr[child] = heap->arr[parent];
            child = parent;
            parent = (child - 1) / 2;
        }

        heap->arr[child] = key;
    }
}

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size)
{
    heap->size = 0;
    heap->max_size = max_size;
    heap->arr = (int *) malloc(max_size * sizeof(int));
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr)
{
    int c = 0;

    heap->arr[(heap->size)++] = key;
    top_down_heap(heap, heap->size - 1, &c);
    *count_ptr = c;
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr)
{
    int c = 0;
    int max = heap->arr[0];

    heap->arr[0] = heap->arr[(heap->size)--];
    top_down_heap(heap, heap->size - 1, &c);
    *count_ptr = c;
    return max;
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr)
{

}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr)
{
    *count_ptr = 0;

    return heap->arr[0];
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr)
{
    int c = 0;
    
    /* 
        The minimum element cannot be a non-leaf node,
        as max heap requires its parent to be greater
        than its children.
        Hence it has to be one of the leaf nodes and 
        the search for the min can begin from there.
    */
    int min = heap->arr[heap->size / 2];
    for (int i = 1 + heap->size / 2; i < heap->size; i++)
    {
        if (++c && heap->arr[i] < min)
            min = heap->arr[i];
    }
    *count_ptr = c;
    return min;
}

// Clears the heap for reuse
void clear_heap(heap_t *heap)
{
    heap->size = 0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap)
{
    heap->size = 0;
    heap->max_size = 0;
    free(heap->arr);
}

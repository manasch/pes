# Using multiple sorting algorithms to sort an array

## Algorithm

```
sort(A, n)
    [min, max] = findMinMax(A, n)
    if (max - min + 1) <= 2 * n) // If the range is less than 2n
        distCountingSort(A, n, min, max)
    else if (Quicksort(A, n) == false)
        mergesort(A, n)
    else
        insertionSort(A, n)
    
    return A
```

Perform checks inside quicksort, take granular approach where you only sort it till 10 elements
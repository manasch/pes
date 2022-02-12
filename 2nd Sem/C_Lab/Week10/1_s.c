#include<stdio.h>
#include"1.h"

int even(int n)
{
    return n%2 == 0;
}

int lessthan22(int n)
{
    return n < 22;
}

int binarySearch(int a[], int start, int end, int elem, int(*p)(int))
{
    int pos = -1;
    int mid;
    if(start > end)
        return pos;
    else
    {
        mid = (start + end)/2;

        if(a[mid] == elem & p(elem))
            pos = mid;
        
        else if(a[mid] > elem)
            return binarySearch(a, start, mid - 1, elem, p);
        
        else
            return binarySearch(a, mid + 1, end, elem, p);
    }
    return pos;
}
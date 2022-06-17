// Create a binary tree using arrays, display the tree in preorder. Check if a given tree is binary search tree or not

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void init(int *);
void insert(int *, int);
void preorder(int *, int);
int checkbst(int *, int, int);


int main()
{
    int arr[MAX];
    int ch;
    int key;

    init(arr);

    while (1)
    {
        printf("\n1) Insert\n2) Preorder Traversal\n3) Check BST\n4) Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter element: ");
            scanf("%d", &key);
            insert(arr, key);
            break;

        case 2:
            printf("\n");
            preorder(arr, 0);
            break;
        
        case 3:
            if(checkbst(arr, 0, 1))
                printf("\nGiven tree is a BST");
            else
                printf("\nGiven tree is not a BST");
            break;
        
        case 4:
            exit(0);

        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}

void init(int *arr)
{
    for (int i = 0; i < MAX; i++)
        arr[i] = -1;
}

void insert(int *arr, int key)
{
    int i = 0;
    while (arr[i] != -1)
    {
        if (i < MAX)
            i++;
    }
    
    arr[i] = key;
}

void preorder(int *arr, int i)
{
    if (arr[i] != -1)
    {
        printf("%d ", arr[i]);
        preorder(arr, (2 * i) + 1);
        preorder(arr, (2 * i) + 2);
    }
    else
        return;
}

int checkbst(int *arr, int i, int res)
{
    if (i < MAX)
    {
        if (res == 0)
            return res;
        else if ((2 * i) + 1 < MAX && arr[(2 * i) + 1] != -1)
        {
            if (arr[(2 * i) + 1] > arr[i])
                return 0;
        }
        else if ((2 * i) + 2 < MAX && arr[(2 * i) + 2] != -1)
        {
            if (arr[(2 * i) + 2] < arr[i])
                return 0;
        }
        return checkbst(arr, i + 1, res);
    }
    else
        return res;
}
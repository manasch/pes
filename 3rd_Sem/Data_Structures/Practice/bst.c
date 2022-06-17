#include <stdio.h>
#include <stdlib.h>

// Implementing binary search tree

typedef struct node
{
    int data;
    struct node *left, *right;
} tnode;

void insert(tnode **, int);
void inorder(tnode *);
tnode *delete(tnode *, int);

int main()
{
    int ch, n;
    tnode *root = NULL;
    
    while (1)
    {
        printf("\n1) Insert");
        printf("\n2) Inorder");
        printf("\n3) Delete");
        printf("\nChoice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
                printf("\nEnter the number to insert: ");
                scanf("%d", &n);
                insert(&root, n);
                break;
            
            case 2:
                printf("\n");
                inorder(root);
                break;
            
            case 3:
                printf("\nEnter the number to delete: ");
                scanf("%d", &n);
                root = delete(root, n);
                break;
            
            default:
                printf("\nInvalid Choice");
                break;
        }
    }
    return 0;
}

void insert(tnode **root, int n)
{
    tnode *temp = (tnode *) malloc(sizeof(tnode));
    temp->left = temp->right = NULL;
    temp->data = n;
    
    tnode *pres, *prev;
    
    if (*root == NULL) //  element to be inserted is the first node
    {
        *root = temp;
    }
    else // any other node
    {
        pres = *root;
        prev = NULL;
        
        while (pres != NULL)
        {
            prev = pres;
            if (n < pres->data)
                pres = pres->left;
            else
                pres = pres->right;
        }
        
        if (n < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }
}

void inorder(tnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

tnode *delete(tnode *root, int n)
{
    tnode *pres = root;
    tnode *prev = NULL;
    tnode *temp, *p, *q;
    
    while ((pres != NULL) && (pres->data != n))
    {
        prev = pres;
        if (n < pres->data)
            pres = pres->left;
        else
            pres = pres->right;
    }
    
    if (pres == NULL)
    {
        printf("\nNode not found");
        return root;
    }
    
    if ((pres->left == NULL) || (pres->right == NULL))
    {
        if (pres->left == NULL)
            q = pres->right;
        else
            q = pres->left;
            
        if (prev == NULL) // deleting root
            return q;
        
        if (pres = prev->right)
            prev->right = q;
        else
            prev->left = q;
        
        free(pres);
    }
    else
    {
        p = NULL;
        temp = pres->right;
        
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
        }
        
        pres->data = temp->data;
            
        if (p != NULL)
            p->left = temp->right;
        else
            pres->right = temp->right;
        free(temp);
    }
    
    return root;
}

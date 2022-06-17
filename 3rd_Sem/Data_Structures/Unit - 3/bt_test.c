#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left, *right;
    int data;
} node;

void insert(node **, int);
void inorder(node *);

int main()
{
    int ch;
    int k;
    node *root;
    root = NULL;
    
    while (1)
    {
        printf("\n1) Insert\n2) Display (Inorder)\n3) Exit\nChoice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &k);
                insert(&root, k);
                break;
                
            case 2:
                printf("\n");
                inorder(root);
                break;
            
            case 3:
                exit(0);
                break;
            
            default:
                printf("\nInvalid Choice");
                break;
        }
    }
}

void insert(node **root, int key)
{
    node *temp, *pres, *prev;
    
    temp = (node *) malloc(sizeof(node));
    temp->left = temp->right = NULL;
    
    if (*root == NULL)
        *root = temp;
    else
    {
        pres = *root;
        prev = NULL;
        
        while (pres != NULL)
        {
            prev = pres;
            if ((pres->left == NULL && pres->right == NULL) || (pres->left != NULL) && (pres->right) != NULL)
                pres = pres->left;
            // else if (prev->left != NULL && prev->right != NULL)
            else
                pres = pres->right;
        }
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

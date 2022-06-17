#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct tnode *right, *left;
} tnode;

void insert(tnode **, int);
void inorder(tnode *);
void postorder(tnode *);
void preorder(tnode *);
int num_nodes(tnode *);
int leaf_count(tnode *);
int height(tnode *);
tnode *rinsert(tnode *, int);
int search(tnode *, int);
int rsearch(tnode *t, int n);
tnode *delete(tnode *, int);


int main()
{
    int ch;
    int n, k;

    tnode *root = NULL;

    while (1)
    {
        printf("\n\n1) Insert");
        printf("\n2) Preorder");
        printf("\n3) Postorder");
        printf("\n4) Inorder");
        printf("\n5) Number of nodes");
        printf("\n6) Number of leaf nodes");
        printf("\n7) Height of tree");
        printf("\n8) Recursive insert");
        printf("\n9) Search");
        printf("\n10 Recursive seach");
        printf("\n11) Delete a node");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element to insert into BST: ");
            scanf("%d", &n);
            insert(&root, n);
            break;
        
        case 2:
            preorder(root);
            break;
        
        case 3:
            postorder(root);
            break;
        
        case 4:
            inorder(root);
            break;
        
        case 5:
            k = num_nodes(root);
            printf("\nNumber of nodes in the tree: %d", k);
            break;
        
        case 6:
            k = leaf_count(root);
            printf("\nNumber of leaf nodes in the tree: %d", k);
            break;

        case 7:
            k = height(root);
            printf("\nHeight of the tree: %d", k);
            break;

        case 8:
            printf("\nEnter the element to insert into BST: ");
            scanf("%d", &n);
            root = rinsert(root, n);
            break;

        case 9:
            printf("\nEnter element to be searched: ");
            scanf("%d", &n);
            k = search(root, n);

            if (k)
                printf("\nElement found");
            else
                printf("\nElement not found");
            break;
        
        case 10:
            printf("\nEnter element to be searched: ");
            scanf("%d", &n);
            k = rsearch(root, n);

            if (k)
                printf("\nElement found");
            else
                printf("\nElement not found");
            break;
        
        case 11:
            printf("\nEnter element to delete: ");
            scanf("%d", &n);
            root = delete(root, n);
            break;
        
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
}

void insert(tnode **t, int k)
{
    tnode *pres, *prev;
    tnode *temp = (tnode *) malloc(sizeof(tnode));
    temp->data = k;
    temp->right = temp->left = NULL;

    if (*t == NULL)
    {
        *t = temp;
    }
    else
    {
        pres = *t;
        prev = NULL;

        while (pres != NULL)
        {
            prev = pres;

            if (k < pres->data)
                pres = pres->left;
            else
                pres = pres->right;
        }
        if (k < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }
}

void inorder(tnode *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

void postorder(tnode *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        inorder(t->right);
        printf("%d ", t->data);
    }
}

void preorder(tnode *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);        
        inorder(t->left);
        inorder(t->right);
    }
}

int num_nodes(tnode *t)
{
    if (t == NULL)
        return 0;
    
    if (t->left == NULL && t->right == NULL)
        return 1;
    
    int l, r;

    l = num_nodes(t->left);
    r = num_nodes(t->right);

    return l + r + 1;
}

int leaf_count(tnode *t)
{
    if (t == NULL)
        return 0;
    
    if (t->left == NULL && t->right == NULL)
        return 1;
    
    int l, r;

    l = leaf_count(t->left);
    r = leaf_count(t->right);

    return l + r;
}

int height(tnode *t)
{
    if (t == NULL)
        return -1;
    
    if (t->left == NULL && t->right == NULL)
        return 0;
    
    int l, r;
    l = height(t->left);
    r = height(t->right);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}

tnode *rinsert(tnode *t, int n)
{
    if (t == NULL)
    {        
        tnode *temp = (tnode *) malloc(sizeof(tnode));
        temp->left = temp->right = NULL;
        temp->data = n;
        return temp;
    }

    if (n < t->data)
        t->left = rinsert(t->left, n);
    else
        t->right = rinsert(t->right, n);
    
    return t;
}

int search(tnode *t, int n)
{
    while (t != NULL && t->data != n)
    {
        if (n < t->data)
            t = t->left;
        else
            t = t->right;
    }

    if (t == NULL)
        return 0;
    else
        return 1;
}

int rsearch(tnode *t, int n)
{
    int res;

    if (t == NULL)
        return 0;

    if (t->data == n)
        return 1;

    if (n < t->data)
        res = rsearch(t->left, n);
    else
        res = rsearch(t->right, n);
    
    return res;
}

tnode *delete(tnode *t, int k)
{
    tnode *pres, *prev, *p, *q, *temp;
    pres = t;
    prev = NULL;

    while (pres != NULL && pres->data != k)
    {
        prev = pres;
        if (k < pres->data)
            pres = pres->left;
        else
            pres = pres->right;
    }

    if (pres == NULL)
    {
        printf("\nKey not found");
        return t;
    }

    if ((pres->left == NULL) || (pres->right == NULL))
    {
        if (pres->left == NULL)
            q = pres->right;
        else
            q = pres->left;
        
        if (prev == NULL)
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

    return t;
}

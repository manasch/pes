// Write a program to delete node from a binary search tree. Consider 3 cases:
// 1) Leaf level deletion
// 2) Subtree level deletiong
// 3) Root deletion


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
} node;

void inorder(node *);
void insert(node **, int);
node *delete(node *, int);


int main()
{
	node *root;
	root = NULL;
	int key;
	int ch;
	
	while (1)
	{
		printf("\n\n1) Insert\n2) Display\n3) Delete\nChoice: ");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1:
				printf("\nEnter the number: ");
				scanf("%d", &key);
				insert(&root, key);
				break;
			
			case 2:
				printf("\n");
				inorder(root);
				break;
			
			case 3:
				printf("\nEnter the number to delete: ");
				scanf("%d", &key);
				root = delete(root, key);
				break;
			
			default:
				printf("\nInvalid Choice");
				break;
		}
	}	
	return 0;	
}


void insert(node **r, int key)
{
	node *temp = (node *) malloc(sizeof(node));
	temp->right = temp->left = NULL;
	temp->data = key;
	
	if (*r == NULL)
		*r = temp;
	else
	{
		node *pres, *prev;
		pres = *r;
		prev = NULL;
		
		while (pres != NULL)
		{
			prev = pres;
			if (key < pres->data)
				pres = pres->left;
			else
				pres = pres->right;
		}
		
		if (key < prev->data)
			prev->left = temp;
		else
			prev->right = temp;
	}
}	


void inorder(node *r)
{
	if (r != NULL)
	{
		inorder(r->left);
		printf("%d ", r->data);
		inorder(r->right);
	}
}


node *delete(node *r, int key)
{
	node *pres, *prev;
	node *temp, *q;
	pres = r;
	prev = NULL;
	
	while (pres != NULL && pres->data != key) // Find the element position to be deleted if exists
	{
		prev = pres;
		if (key < pres->data)
			pres = pres->left;
		else
			pres = pres->right;
	}
	
	if (pres == NULL) // Element not found
	{
		printf("\nElement doesn't exist");
		return r;
	}
	if ((prev->left == NULL) || (prev->right == NULL)) // Handles the cases where the node has 1 or 2 children
	{
		if (pres->left == NULL)
			q = pres->right;
		else
			q = pres->left;
		
		if (prev == NULL)
			return q;
		
		if (pres = prev->right)
			pres->right = q;
		else
			pres->left = q;
		
		free(pres);
	}
	else // element to be deleted has both the subtrees present
	{
		q = NULL;
		temp = pres->right;
		
		while (temp->left != NULL)
		{
			q = temp->left;
			temp = temp->left;
		}
		
		pres->data = temp->data;
		
		if (q != NULL)
			q->left = temp->right;
		else
			pres->right = temp->right;
		
		free(temp);
	}
}

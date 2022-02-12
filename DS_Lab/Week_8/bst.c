#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
} NODE;

void insert(NODE **, int);
void preorder(NODE *);
NODE *delete (NODE *, int);

int main()
{
	NODE *root = NULL;
	int op, k, q = 0;

	while (!q)
	{
		printf("\n1> insert\n2> delete\n3> display\n4> exit\nenter choice: ");
		scanf("%d", &op);

		switch (op)
		{
			case 1:
				printf("enter key: ");
				scanf("%d", &k);
				insert(&root, k);
				break;
			case 2:
				printf("enter key: ");
				scanf("%d", &k);
				delete(root, k);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				q = 1;
				exit(0);
				
			default:
				printf("invalid choice\n");
				break;
		}
	}

	return 0;
}

void insert(NODE **t, int key)
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->data = key;
	temp->left = temp->right = NULL;

	if (*t == NULL)
	{
		*t = temp;
	}
	else
	{
		NODE *pres, *prev;
		pres = *t, prev = NULL;

		while (pres != NULL)
		{
			prev = pres;
			if (key < pres->data)
			{
				pres = pres->left;
			}
			else
			{
				pres = pres->right;
			}
		}

		if (key < prev->data)
		{
			prev->left = temp;
		}
		else
		{
			prev->right = temp;
		}
	}
}

void preorder(NODE *t)
{
	if (t != NULL)
	{
		printf("%d", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

NODE *delete (NODE *t, int key)
{
	NODE *pres, *prev, *p, *q, *temp;
	pres = t, prev = NULL;

	while (pres != NULL && pres->data != key)
	{
		prev = pres;
		if (key < pres->data)
		{
			pres = pres->left;
		}
		else
		{
			pres = pres->right;
		}
	}

	if (pres == NULL)
	{
		printf("key not found\n");
		return t;
	}
	if (pres->left == NULL || pres->right == NULL)
	{
		if (pres->left == NULL)
		{
			p = pres->right;
		}
		else
		{
			p = pres->left;
		}
		if (prev == NULL)
		{
			return p;
		}
		if (pres == prev->right)
		{
			prev->right = p;
		}
		else
		{
			prev->left = p;
		}
		free(pres);
	}
	else
	{
		q = NULL;
		temp = pres->right;

		while (temp->left != NULL)
		{
			q = temp;
			temp = temp->left;
		}

		pres->data = temp->data;
		if (q != NULL)
		{
			q->left = temp->right;
		}
		else
		{
			pres->right = temp->right;
		}
		free(temp);
	}
	return t;
}

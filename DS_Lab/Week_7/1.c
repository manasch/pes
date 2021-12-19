//1) Create a binary search tree to store srn of students where srn's are strings. Implement an insert function of the binary search tree by comparing strings, also implement a function to print all sorted srn's in ascending order. Implement a function to search an SRN.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char srn[5];
	struct student *left, *right;
} student;

void insert(student **, char *);
void display(student *);
int search(student *, char *);

int main()
{
	student *root;
	root = NULL;
	int ch;
	char srn[5];
	int res;
	
	while (1)
	{
		printf("\n1) Insert\n2) Display\n3) Search\n4) Exit\nChoice: ");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1:
				printf("\nEnter SRN: ");
				scanf("%s", srn);
				insert(&root, srn);
				break;
			
			case 2:
				printf("\n");
				display(root);
				break;
			
			case 3:
				printf("\nEnter SRN to search: ");
				scanf("%s", srn);
				if(search(root, srn))
					printf("\nSRN FOUND");
				else
					printf("\nSRN NOT FOUND");
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

void insert(student **s, char *srn)
{
	student *temp;
	temp = (student *) malloc(sizeof(student));
	temp->left = temp->right = NULL;
	strcpy(temp->srn, srn);
	
	student *pres, *prev;
	
	if (*s == NULL)
		*s = temp;
	else
	{
		pres = *s;
		prev = NULL;
		
		while (pres != NULL)
		{
			prev = pres;
			
			if (strcmp(pres->srn, srn) < 0)
				pres = pres->right;
			else if (strcmp(pres->srn, srn) > 0)
				pres = pres->left;
			else
			{
				printf("\nSRN already exists");
				free(temp);
				return;
			}
		}

		if (strcmp(prev->srn, srn) > 0)
			prev->left = temp;
		else if (strcmp(prev->srn, srn) < 0)
			prev->right = temp;
		else
			return;
	}
}


void display(student *s)
{
	if (s != NULL)
	{
		display(s->left);
		printf("%s ", s->srn);
		display(s->right);
	}	
}


int search(student *s, char *srn)
{
	while (s != NULL)
	{
		if (strcmp(s->srn, srn) < 0)
			s = s->right;
		else if (strcmp(s->srn, srn) > 0)
			s = s->left;
		else
			return 1;
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char ch;
    struct node *left, *right;
} node;

void inorder(node *);
void postorder(node *);
node *create_tree(char *);

int main()
{
    char postfix[50];
    printf("\nEnter a postfix expression: ");
    scanf("%s", postfix);
    
    node *root = NULL;
    root = create_tree;
    
    printf("\nExpression in inorder: ");
    inorder(root);
}

void push(node **stk, int *top, node *ptr)
{
    ++*top;
    stk[*top] = ptr;
}

node *pop(node **stk, int *top)
{
    node *temp = stk[*top];
    --*top;
    return temp;
}

int isop(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
        case '-':
        case '/': return 1; break;
        default: return 0; break;
    }
}

node *create_tree(char *postfix)
{
    node *stk[100];
    node *temp;
    
    int top = -1;
    char ch;
    int i = 0;
    
    while ((ch = postfix[i]) != '\0')
    {
        temp = (node *) malloc(sizeof(node));
        temp->ch = ch;
        temp->left = temp->right = NULL;
        
    }
}

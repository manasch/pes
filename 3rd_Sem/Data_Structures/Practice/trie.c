#include <stdio.h>
#include <stdlib.h>
#define MAX 255

typedef struct trienode
{
    struct trienode *child[MAX];
    int eow;
} trie;

typedef struct stack
{
    trie *ptr;
    int index;
} stack;

trie *create_node();
void insert(trie *root, char *key);
void display(trie *root, char *word, int *length);
int search(trie *root, char *key);
void delete(trie *root, char *key);
void push(stack *s, trie *curr, int k, int *top);
stack pop(stack *s, int *top);
void delete(trie *root, char *key);
int check(trie *curr);
void display_prefix(trie *root, char *word, char *prefix, int *length);


int main()
{
    int ch;
    char key[50], prefix[50];
    int res;
    trie *root = create_node();
    
    char word[50];
    int length;
    
    while (1)
    {
        printf("\n1) Insert");
        printf("\n2) Display");
        printf("\n3) Search");
        printf("\n4) Delete");
        printf("\n5) Prefix");
        printf("\nChoice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
                printf("\nEnter the key: ");
                scanf("%s", key);
                insert(root, key);
                break;
            case 2:
                length = 0;
                display(root, word, &length);
                break;
            case 3:
                printf("\nEnter the key: ");
                scanf("%s", key);
                res = search(root, key);
                if (res)
                    printf("\nString found");
                else
                    printf("\nString not found");
                break;
            case 4:
                printf("\nEnter key to delete: ");
                scanf("%s", key);
                delete(root, key);
                break;
            case 5:
                length = 0;
                printf("\nEnter the prefix: ");
                scanf("%s", prefix);
                display_prefix(root, word, prefix, &length);
                break;
            default:
                printf("\nInvalid Choice");
                fflush(stdout);
                break;
        }
    }
    return 1;
}

trie *create_node()
{
    trie *temp;
    temp = (trie *) malloc(sizeof(trie));
    temp->eow = 0;
    
    for (int i = 0; i < MAX; i++)
    {
        temp->child[i] = NULL;
    }
    return temp;
}

void insert(trie *root, char *key)
{
    for (int i = 0; key[i]; i++)
    {
        if (root->child[key[i]] == NULL)
        {
            root->child[key[i]] = create_node();
        }
        root = root->child[key[i]];
    }
    root->eow = 1;
}

void display(trie *root, char *word, int *length)
{
    trie *curr = root;
    for (int i = 0; i < MAX; i++)
    {
        if (curr->child[i] != NULL)
        {
            word[*length] = i;
            ++*length;
            if (curr->child[i]->eow == 1)
            {
                printf("\n");
                for (int j = 0; j < *length; j++)
                {
                    printf("%c", word[j]);
                }
            }
            display(curr->child[i], word, length);
        }
    }
    --*length;
}

int search(trie *root, char *key)
{
    for (int i = 0; key[i]; i++)
    {
        if (root->child[key[i]] == NULL)
        {
            return 0;
        }
        root = root->child[key[i]];
    }
    if (root->eow == 1)
        return 1;
    return 0;
}

void delete(trie *root, char *key)
{
    trie *curr = root;
    int index, k;
    int top = -1;
    stack s[MAX], temp;
    
    for (int i = 0; key[i]; i++)
    {
        index = key[i];
        if (curr->child[index] == NULL)
        {
            printf("\nString not found");
            return;
        }
        push(s, curr, index, &top);
        curr = curr->child[index];
    }
    
    curr->eow = 0;
    push(s, curr, -1, &top);
    
    while (1)
    {
        temp = pop(s, &top);
        if (temp.index != -1)
        {
            temp.ptr->child[temp.index] = NULL;
        }
        
        if (temp.ptr == root)
            break;
        
        k = check(temp.ptr);
        if ((k >= 1 || temp.ptr->eow == 1))
            break;
        else
            free(temp.ptr);
    }
}

void push(stack *s, trie *curr, int k, int *top)
{
    ++*top;
    s[*top].ptr = curr;
    s[*top].index = k;
}

stack pop(stack *s, int *top)
{
    stack temp;
    temp = s[*top];
    --*top;
    return temp;
}

int check(trie *curr)
{
    int count = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (curr->child[i] != NULL)
        {
            count++;
        }
    }
    return count;
}

void display_prefix(trie *root, char *word, char *prefix, int *length)
{
    trie *curr = root;
    int index;
    
    for (int i = 0; prefix[i]; i++)
    {
        index = prefix[i];
        if (curr->child[index] == NULL)
        {
            printf("\nWord with Prefix %s doesn't exist", prefix);
            return;
        }
        else
        {
            word[*length] = index;
            ++*length;
            curr = curr->child[index];
        }
        
        if (curr->eow == 1)
        {
            printf("\n");
            for (int j = 0; j < *length; j++)
            {
                printf("%c", word[*length]);
            }
        }
    }
    display(curr, word, length);
}


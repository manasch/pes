#include<stdio.h>
#include<string.h>

void swap(char *, char *);
void recur_perm(char *, int, int);

int main()
{
    char word[20];
    printf("Enter the word: ");
    scanf("%s", word);

    int length = strlen(word);
    recur_perm(word, 0, length - 1);

    return 0;
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void recur_perm(char *word, int beg, int end)
{
    if (beg == end)
        printf("%s\n", word);
    else
    {
        for (int i = beg; i <= end; i++)
        {
            swap((word + beg), (word + end));
            recur_perm(word, beg + 1, end);
            swap((word + beg), (word + i));
        }
    }
}
// Implement Josephus Problem

#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    int num;
    struct person *next;
} person;

void init(person **, int);
int josephus(person **);

int main()
{
    int n;
    int winner;
    person *p;

    printf("\nEnter the number of people: ");
    scanf("%d", &n);

    init(&p, n);

    winner = josephus(&p);

    printf("\n\nThe winner is %d", winner);

    return 0;
}

void init(person **p, int n)
{
    // Generating the circle of people
    person *pres = NULL;

    for (int i = 1; i <= n; i++)
    {
        person *temp = (person *) malloc(sizeof(person));
        temp->num = i;
        temp->next = NULL;

        if (i == 1)
        {
            *p = temp;
            (*p)->next = *p;
            pres = *p;
        }
        else
        {
            pres->next = temp;
            temp->next = *p;
            pres = pres->next;
        }
    }
}

int josephus(person **p)
{
    person *next;

    while ((*p)->next != *p)
    {
        next = (*p)->next;
        (*p)->next = next->next;
        (*p) = (*p)->next;
        printf("\nPerson %2d was killed", next->num);
        free(next);
    }
    return (*p)->num;
}
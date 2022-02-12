#include<stdio.h>
#include<stdlib.h>

typedef struct poly
{
    int px;
    int py;
    int coef;
    
    struct poly *next;
}poly_t;

typedef struct lis
{
    poly_t *head;
}list_t;

void init(list_t *);
void accept_poly(list_t *, int, int, int);
void display_poly(list_t *);
void addpoly(list_t *, list_t *, list_t *);


int main()
{
    list_t l1, l2, l3;
    int tc, tx, ty;

    init(&l1);
    printf("\nEnter the number of elements in 1st polynomial: ");
    int n1;
    scanf("%d", &n1);

    int i = 0;
    while(i < n1)
    {
        printf("\nEnter Coefficient, X-exponent and Y-exponent of term %d: ", ++i);
        scanf("%d %d %d", &tc, &tx, &ty);
        accept_poly(&l1, tc, tx, ty);
    }

    init(&l2);
    printf("\nEnter the number of elements in 2nd polynomial: ");
    int n2;
    scanf("%d", &n2);

    i = 0;
    while(i < n2)
    {
        printf("\nEnter Coefficient, X-exponent and Y-exponent of term %d: ", ++i);
        scanf("%d %d %d", &tc, &tx, &ty);
        accept_poly(&l2, tc, tx, ty);
    }

    printf("\nPolynomial 1: "); display_poly(&l1);
    printf("\nPolynomial 2: "); display_poly(&l2);

    init(&l3);
    addpoly(&l1, &l2, &l3);


    printf("\nSum = "); display_poly(&l3);
    return 0;
}

void init(list_t *l)
{
    l->head = NULL;
}

void accept_poly(list_t *l, int coef, int px, int py)
{
    poly_t *temp, *pres;
    temp = (poly_t *)malloc(sizeof(poly_t));

    temp->coef = coef;
    temp->px = px;
    temp->py = py;
    temp->next = NULL;

    if(l->head == NULL)
        l->head = temp;
    else
    {
        pres = l->head;
        while(pres->next != NULL)
            pres = pres->next;
        
        pres->next = temp;
    }
}

void addpoly(list_t *l1, list_t *l2, list_t *l3)
{
    poly_t *p1 = l1->head;
    poly_t *p2 = l2->head;
    poly_t *p3 = l3->head;

    while(p1 != NULL) //To copy elements of polynomial in another linked list
    {
        poly_t *temp;
        temp = (poly_t *)malloc(sizeof(poly_t));
        temp->coef = p1->coef; 
        temp->px = p1->px;
        temp->py = p1->py;
        temp->next = NULL;

        if(l3->head == NULL)
        {
            l3->head = temp;
            p3 = l3->head;  // Make sure to do this otherwise it will become a dangling pointer, result of 2 hours of debugging
        }
        else
        {
            p3->next = temp;
            p3 = p3->next;
        }

        p1 = p1->next;
    }
    p3 = l3->head;

    int flag; // To check if it has already been added to the list
    while(p2 != NULL)
    {
        flag = 0;
        p3 = l3->head;        
        while(p3 != NULL)
        {
            if(p2->px == p3->px && p2->py == p3->py)
            {
                p3->coef = p3->coef + p2->coef;
                flag = 1;
            }
            p3 = p3->next;
        }

        p3 = l3->head;

        if(flag == 0)
        {
            poly_t *temp = (poly_t *)malloc(sizeof(poly_t));
            temp->coef = p2->coef;
            temp->px = p2->px;
            temp->py = p2->py;
            temp->next = NULL;

            while(p3->next != NULL)
                p3 = p3->next;

            p3->next = temp;
        }
        p2 = p2->next;
    }
}

void display_poly(list_t *l)
{
    if(l->head == NULL)
        return;

    poly_t *pres;
    pres = l->head;
    while(pres != NULL)
    {
        if(pres->next == NULL)
            printf("%dx^%dy^%d", pres->coef, pres->px, pres->py);    
        else
            printf("%dx^%dy^%d + ", pres->coef, pres->px, pres->py);
        pres = pres->next;
    }
}
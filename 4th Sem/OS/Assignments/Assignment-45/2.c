/*
    Write a C program to stimulate segmentation
    Take as input:
    1) Segment number
    2) Base address
    3) Segment limit
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int seg;
    int base;
    int limit;
    struct list *next;
} List;

List *p;

void insert_list(List *segmentList, int base, int limit, int seg)
{
    if (p == NULL)
    {
        p = malloc(sizeof(List));
        p->limit = limit;
        p->base = base;
        p->seg = seg;
        p->next = NULL;
    }
    else
    {
        while(segmentList->next != NULL)
            segmentList = segmentList->next;

        segmentList->next = malloc(sizeof(List));
        segmentList->next->limit = limit;
        segmentList->next->base = base;
        segmentList->next->seg = seg;
        segmentList->next->next = NULL;
        
    }
}

int value_limit(List *segmentList, int seg)
{
    while(segmentList != NULL && segmentList->seg != seg)
        segmentList = segmentList->next;
    
    if(segmentList == NULL)
    {
        printf("\nSegment not found...\n");
        return -1;
    }
    else
        return segmentList->limit;
}

int base_value(List *segmentList,int seg)
{
    while(segmentList != NULL &&segmentList->seg != seg)
        segmentList = segmentList->next;
    
    if(segmentList == NULL)
    {
        printf("\nSegment not found...\n");
        return -1;
    }
    else
        return segmentList->base;
}


int main()
{    
    p = NULL;
    int seg, offset, limit, base, c, s, physicalAddr;
    printf("Enter the segment Table\n");
    printf("Enter -1 to stop entries\n");

    do
    {
        printf("Enter segement number: ");
        scanf("%d", &seg);
        if(seg != -1)
        {
            printf("Enter base value: ");
            scanf("%d", &base);
            printf("Enter limit: ");
            scanf("%d", &limit);
            insert_list(p, base, limit, seg);
        }
    } while(seg != -1);

    printf("\n\n");
    printf("Segmentation Table \nSegment Number \tBase Value \tLimit Value\n");
    List *q;
    q = p;
    while(q != NULL)
    {
        printf("%d \t\t%d \t\t%d\n", q->seg, q->base, q->limit);
        q = q->next;
    }
    printf("\n\n");

    printf("Enter offset: ");
    scanf("%d", &offset);
    printf("Enter segementation number: ");
    scanf("%d", &seg);
    c = value_limit(p, seg);
    if( c != -1)
    {
        s = base_value(p, seg);
    
        if(offset < c)
        {
            physicalAddr = s + offset;
            printf("Physical Address %d\n", physicalAddr);
        }
        else{
            printf("Offset Error\n");
        }
    }
}
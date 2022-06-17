#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info, priority;
    struct node *link;
}NODE;
NODE *front = NULL;

void insert(int value, int rank){
    NODE *tmp, *x;

    tmp = (NODE *)malloc(sizeof(NODE));
    tmp->info = value;
    tmp->priority = rank;

    if (front == NULL || rank < front->priority){
        tmp->link = front;
        front = tmp;
    }
    else{
        x = front;
        while (x->link != NULL && x->link->priority <= rank)
            x = x->link;
        tmp->link = x->link;
        x->link = tmp;
    }
}

void del(){
    NODE *tmp;
    if (front == NULL)
        printf("\nQueue Underflow\n");
    else{
        tmp = front;
        printf("Deleted value %d with Priority %d\n", tmp->info, tmp->priority);
        front = front ->link;
        free(tmp);
    }
}

void display(){
    NODE *ptr;
    ptr = front;

    if (front == NULL){
        printf("\nQueue is empty\n");
        return; //a
    }
    while (ptr->link != NULL){
        printf("%d[%d] -> ",ptr->info, ptr->priority);
        ptr = ptr->link;
    }
    printf("%d[%d]\n",ptr->info, ptr->priority);
}

int main(){
    int choice, item, priority;

    do{
        printf("\nEnter Your Choice\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Value and Priorty: ");
                scanf("%d %d", &item, &priority);
                insert(item, priority); break;
            case 2:
                del(); break;
            case 3:
                display(); break;
            case 4:
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choice != 4);
    
    return 0;
}
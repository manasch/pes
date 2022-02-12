#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};//NODE_t

struct mylist{
    struct node *head;
};

void initialize(struct mylist *);
void display(const struct mylist *);
void insert(struct mylist *, int);

int main(){
    struct mylist l1; //head=undefined
    initialize(&l1); //only the address is passed so that it doesn't create a copy of the list and waste memory
    printf("Enter the No. of elements you want to insert: ");
    int n,i,e;//e=element
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter the element: ");
        scanf("%d",&e);
        insert(&l1,e);
    }
    display(&l1);

    return 0;
}

void initialize(struct mylist *l){
    l->head = NULL;
}

void insert(struct mylist *l, int data){
    printf("Element receieved : %d\n",data);
    struct node *temp = (struct node*)malloc(sizeof(struct node));//initialzed undefined values
    temp->info=data;
    temp->link=NULL;

    if(l->head == NULL)
        l->head = temp;
    else{
        struct node *pres = l->head;
        struct node *prev = NULL;
        while(pres != NULL && pres->info < data){
            prev = pres;
            pres = pres->link;
        }
        if (prev == NULL){
            temp->link = pres;
            l->head = temp;
        }
        else{
            temp->link = pres;
            prev->link = temp;
        }
    }
}

void display(const struct mylist *l){
    struct node *traverse = l->head;
    printf("\nEntered elements are: ");
    if(traverse == NULL)
        printf("\nNo elements to display");
    else{
        while(traverse != NULL){
            printf("%d ",traverse->info);
            traverse = traverse->link;
        }
    }
}
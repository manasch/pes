#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

void display(struct node *);
void free_list(struct node *);
//typedef struct node NODE_T;

int main(){
    struct node *s;
    s = (struct node *)malloc(sizeof(struct node));

    s->info = 100;
    s->link = (struct node *)malloc(sizeof(struct node));

    s->link->info = 300;
    s->link->link = (struct node *)malloc(sizeof(struct node));

    s->link->link->info = 400;
    s->link->link->link = NULL;

    display(s);

    //free(s); becomes a dangling pointer so not recommended, only the first memory location gets freed
    //and the other nodes would become inaccessable to clear and memory is waster, hence a functions is created
    //s=NULL;
    free_list(s);
    return 0;
}

void display(struct node *s){
    printf("\nElements are: ");
    while(s){ //or s!=NULL
        printf("%d\t",s->info); 
        s=s->link;
    }
}

void free_list(struct node *p){
    struct node *temp = p;
    while(p!=NULL){
        p=p->link;
        free(temp);
        temp = p;
    }
    display(p);
}
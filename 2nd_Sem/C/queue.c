#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct comp{
    char details[MAX];
    int priority;
};

struct node{
    struct comp c;
    struct node *link;
};

struct pq{ //pq = priority queu
    struct node *head;
};

int main(){
    //struct node *
}
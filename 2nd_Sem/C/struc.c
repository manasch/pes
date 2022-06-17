#include<stdio.h>

struct student{
    int rno;
    char name[20];
    int marks;
};

//typedef struct student S;
/*
void main(){
    struct student s1 = {10,"john",20};
    printf("%d %s %d\n",s1.rno,s1.name,s1.marks);

    struct student s2;
    printf("Enter Student roll no.: ");
    scanf("%d",&s2.rno);
    printf("Enter student name: ");
    scanf(" %s",s2.name);
    printf("Enter marks: ");
    scanf("%d",&s2.marks);
    printf("%d %s %d",s2.rno,s2.name,s2.marks);

}*/

void read(struct student*);
void display(struct student*);

void main(){
    struct student s1;
    printf("Enter the details");
    read(&s1);
    printf("\nThe details are: ");
    display(&s1);
}

void read(struct student *s){
    printf("\nEnter RNo. , Name , Marks\n");
    scanf("%d",&(s->rno));
    scanf(" %s",s->name);
    scanf("%d",&(s->marks));
}

void display(struct student *s){
    printf("\nRno : %d",s->rno);
    printf("\nname : %s",s->name);
    printf("\nmarks : %d",s->marks);
}
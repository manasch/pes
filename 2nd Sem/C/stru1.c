#include<stdio.h>

struct student{
    int rno;
    char name[50];
    int marks;
};

typedef struct student Stud;

int find_avg(Stud *, int);

int main(){
    Stud st[50];
    int i,n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter details of student %d: \n",i);
        scanf("%d %s %d", &st[i].rno, st[i].name, &st[i].marks);
    }
    printf("\nStudent Information:\n");
    for(i=0;i<n;i++)
        printf("%d\t %s\t %d\n", st[i].rno, st[i].name, st[i].marks);

    int avgm = find_avg(st,n);
    printf("\nAvg Marks = %d",avgm);
}
/*
int find_avg(Stud s[], int n){
    int r,sum=0;
    for(int i=0;i<n;i++)
        sum+=s[i].marks;

    r = sum/n;
    return r;
}*/

int find_avg(Stud *s, int n){
    int r,sum=0;
    for(int i=0;i<n;i++)
        sum+=(s+i)->marks;
    r = sum/n;
    return r;
}
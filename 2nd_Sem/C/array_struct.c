#include<stdio.h>


struct student{
    int rno;
    char name[100];
    int marks;
}; // }S1[100]; an array of structures will be created here

int main(){
   //struct student s1[50];
   struct student s1[] = {{1,"joh",45},{2,"fdg",54},{45,"dsfg",45}};
   //printf("%d",s1[0].rno);
   struct student *p1 = s1;
   printf("%d", (p1+1)->rno);
   //printf("%d", *p1); //doesn't seem to work no idea
}
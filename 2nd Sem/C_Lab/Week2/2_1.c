#include<stdio.h>

int main()
{
    int marks;
    printf("Enter the marks: ");
    scanf("%d",&marks);
    
    if (marks>85 && marks<=100)
        printf("You got Grade A");
    else if (marks>60 && marks<=85)
        printf("You got Grade B");
    else if (marks>40 && marks<=60)
        printf("You got Grade C");
    else if (marks>30 && marks<=40)
        printf("You got Grade D");
    else
        printf("You got Grade F");
    
    return 0;
}
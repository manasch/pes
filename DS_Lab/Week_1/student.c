#include<stdio.h>
#include<stdlib.h>

typedef struct sub
{
    int code;
    int score;
    char subname[20];
}SUB;


typedef struct student
{
    int srn;
    char name[20];
    int sem;
    SUB marks[5];
}STUD;

void accept(STUD *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the student name: ");
        scanf("%s", s[i].name);
        fflush(stdin);

        printf("Enter the studen SRN: ");
        scanf("%d", &s[i].srn);
        
        printf("Enter the semester: ");
        scanf("%d", &s[i].sem);

        for (int j = 0; j < 5; j++)
        {
            printf("\nEnter the subject name and code: ");
            scanf("%s %d", s[i].marks[j].subname, &s[i].marks[j].code);
            fflush(stdin);

            printf("\nEnter the marks: ");
            scanf("%d", &s[i].marks[j].score);
        }
    }
}

float classavg(STUD *s, int cod, int n)
{
    int sum = 0;
    float avg;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (s[i].marks[j].code == cod)
                sum = sum + s[i].marks[j].code;
        }
    }
    avg = sum / n;
    return avg;
}


int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    STUD *s = (STUD *)malloc(n * sizeof(STUD));

    accept(s, n);

    printf("\nEnter the subject code to find average: ");
    int scode;
    scanf("%d", &scode);
    printf("\nClass average in %d: %f", scode, classavg(s, scode, n));

}
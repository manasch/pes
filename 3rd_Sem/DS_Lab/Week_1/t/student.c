#include <stdio.h>
#include <stdlib.h>

typedef struct sub
{
    int code;
    char subn[20];
    int score;
} SUB;

typedef struct student
{
    int srn;
    char name[100];
    int sem;
    SUB marks[5];
} STUDENT;
3
void srnsort(STUDENT arr[], int size)
{
    STUDENT temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j].srn < arr[j + 1].srn)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(STUDENT arr[], int size)
{
    printf("SRN\tName\tSemester\n");
    for (int i = 0; i < size; i++)
        printf("%d\t%s\t%d\n", arr[i].srn, arr[i].name, arr[i].sem);
    printf("\n");
}

void main()
{
    int n, sum = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    STUDENT *stud = (STUDENT *) malloc(n * sizeof(STUDENT));
    for (int i = 0; i < n; i++)
    {
        printf("For student %d\n", i + 1);
        printf("Enter srn: ");
        scanf("%d", &stud[i].srn);
        printf("Enter name: ");
        scanf("%s", stud[i].name);
        printf("Enter semester: ");
        scanf("%d", &stud[i].sem);
        for (int j = 0; j < 5; j++)
        {
            printf("Enter subject code: ");
            scanf("%d", &stud[i].marks[j].code);
            printf("Enter subject name: ");
            scanf("%s", stud[i].marks[j].subn);
            printf("Enter marks: ");
            scanf("%d", &stud[i].marks[j].score);
        }
        sum += stud[i].marks[1].score;
    }
    printf("Class average in %s is %d\n", stud[0].marks[0].subn, sum / n);
    
    int a = sizeof(STUDENT);
    srnsort(stud, a);
    display(stud, a);
}

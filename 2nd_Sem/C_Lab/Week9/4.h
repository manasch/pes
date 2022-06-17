typedef struct student
{
    int rno;
    char name[20];
}student;

void swap(student **ptr1, student **ptr2);
void app(student **ptr, int n, void (*f)(student**, int));
void sort_roll(student **ptr, int n);
void sort_name(student **ptr, int n);
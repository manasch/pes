#include<stdio.h>
#include<stdlib.h>

//int main()
//{   
    /*
    int a = 10;
    int *p = &a;
    char *s;
    printf("%p %p", &a, p);
    printf("\n%d %d", a, *p);
    printf("\n%d", sizeof(s));
    */
    /*
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d %s", n, n%2 ? "is Odd" : "is Even");
    */
    /*
    int n = 5;
    int p = 1;
    while(--n)
    {
        p*=n;
    }
    printf("%d", p);
    */
   /*
    int a =100, b = 200;
    printf("a %d b %d", a, b);
    swap(&a, &b);
    printf("\na %d b %d", a, b);
    */
//}
/*
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;   
    *b = temp;
}
*/

typedef struct s1
{
    int j;
    char k;
}s;


enum days {sun = 1, mon, tue = 5, wed, thu = 10, fri, sat};

int main()
{
    /*
    int a[10];
    for (int i = 0; i<20; i++)
        printf("%d(%d)\t", i, a[i]);
    printf("\n%d", sizeof(a));

    int *p;
    printf("%d",*p);
    */
   //printf("%d", sizeof(s));

    printf("%d %d %d %d %d %d %d",sun, mon, tue, wed, thu, fri, sat);
    enum days d;
    d = sun;
    printf("\n%d\n",d);

    for(enum days i=sun; i < sat; i++)
        printf("%2d", i);


}
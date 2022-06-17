#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>

/*
typedef struct player
{
    char name[20];
    int id;
    int score;
    int year;  
}PLAYER;

void display(PLAYER *p)
{
    printf("The data stored in the file: \n");
    int i = 0;
    while(i < 6)
    {
        printf("Name: %s\nID: %d\nScore: %d\nYear: %d", (p+i)->name, (p+i)->id, (p+i)->score, (p+i)->year);
        i++;
    }
}

int main()
{
    FILE *fp = fopen("test.txt", "r");
    if(fp == NULL)
        printf("File does not exist");
    else     
    {
        PLAYER *p[10];
        char a[500];
        char *item;
        while(fgets(a, 500, fp))
        {
            item = strtok(a, )
        }
        display(p);
    }
    fclose(fp);
    return 0;
}
*/

/*
int main()
{
    FILE *fpr = fopen("data.txt","r"); // read mode 1 mark
    FILE *fpw = fopen("output.txt","w"); // write mode 1mark
    //char data[1000];
    char ch;
    while((ch = getc(fpr)) != EOF) // 1mark
        {
            if(ch == '\n')
            {}
                putc(',', fpw);
                putc('\n', fpw);
            }
            else
                putc('%s',ch, fpw);
        }
    fclose(fpr); 
    fclose(fpw);
    return 0;
}
*/
/*
void f1(int q)
{
    q = 20;
}

void f2(int *q)
{
    int temp = 200;
    q = &temp;
}

int main()
{
    double y = 6.5;
    int x = 100;
    int *p;
    p = &x;
    f1(y);
    f2(p);
    printf("%d %d", x, *p);

}
*/

/*
void read(int *a, int n)
{
    int i = 0;
    while(i < n)
    {
        scanf("%d ", (a+i));
        i++;
    }
}

void disp(int *a, int n)
{
    int i = 0;
    while(i < n)
    {
        printf("%d ", *(a+i));
        i++;
    }
}

int main()
{
    int a[10];
    int n;
    scanf("%d", &n);
    read(a,n);
    disp(a,n);
}
*/

/*
int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
*/
/*
int main()
{
    int *p;
    int a = 10;
    p = &a;
    printf("%d\n",(*p)+1);// 11 ,p is not changed
    printf("before *p++ %p\n",p); //address of p
    printf("%d\n",*p++); // same as *p and then p++ i.e 10
    printf("after *p++ %p\n",p); //address incremented by the size of type of value stored in it   
    return(0);
}
*/
/*
int main()
{
    char a[] = "pesdf";
    printf("%s\n", a);
    char *p = a;
    printf("%s\n", p);
    p++;
    printf("%s", p);
}
*/
/*
int pattern_match(char txt[], int n, char pat[], int m)
{
    int i, j;
    int res = -1;
    for(i = 0;res == -1 && i < n-m; i++)
    {
        for(j = 0; j < m && txt[i + j] == pat[j]; j++);
        if(j == m)
            res = i;
    }
    return res;
}


int main()
{
    char txt[100];
    char pat[100];
    printf("Enter string: ");
    scanf("%[^\n]s", txt);
    fflush(stdin);
    printf("\nEnter pattern: ");
    scanf("%[^\n]s", pat);
    int n = strlen(txt);
    int m = strlen(pat);
    int pos = pattern_match(txt, n, pat, m);
    if(pos == -1)
        printf("\nNot found");
    else
        printf("\nFound at %d", pos);
    
    return 0;
}
*/
/*
int main()
{
    char s[20] = "apple\tis\tstrong";
    char *token = strtok(s, "\t");
    while(token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "\t");
    }
}
*/
/*
struct Sample
 {
int a; 
struct Sample *p; 
}; 
int main()
 {
printf("%d\n",sizeof(struct Sample) ); // implementation specific struct Sample s;
struct Sample s;
s.a = 100; s.p = &s;
printf("%d %d %d\n", s.a, s.p->a, s.p->p->a); // all 100
return 0;
}
*/

int main ()
{
 FILE *fp;
 fp = fopen ("File.txt", "r"); // File with this name doesn’t exist
 printf("Value of errno: %d %s\n ", errno, strerror(errno));
 perror("Bad code");
 return 0;
}
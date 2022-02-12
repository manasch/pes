#include<stdio.h>
#include<stdlib.h>
/*
struct sample{
    int a;
    int*b;
};
*/

//int main(){
/*
    struct sample s1;
    s1.a = 100;
    s1.b = &(s1.a);
    printf("\n%d %d",s1.a,*(s1.b));

    struct sample s2 = s1;
    printf("\n%d %d",s2.a,*(s2.b));

    *(s2.b) = 200;
    printf("\n%d %d",s1.a,*(s1.b));
    printf("\n%d %d",s2.a,*(s2.b));
*/
/*
    struct sample s1;
    int c = 200;
    s1.a = 100;
    s1.b = &c;
    struct sample s2;
    printf("%d %d %d\n",*(s1.b),c,*(s2.b));
    *(s1.b) = 1000;
    printf("%d %d %d\n",*(s1.b),c,*(s2.b));
*/

/*
    struct sample s1;
    s1.a = 100;
    s1.b = (int*)malloc(sizeof(int));
    *(s1.b) = 1000;

    struct sample s2 = s1;
    printf("%d %d\n",*(s1.b),*(s2.b));
}
*/

struct sample{
    int a;
    struct sample *p;
};

int main(){
    printf("%d\n", sizeof(struct sample));
    struct sample s1;
    s1.a = 100;
    s1.p = &s1;
    printf("%d %d\n",s1.a,(*(s1.p)).a);
    printf("%d %d\n",s1.a,s1.p->a);
    return 0;
}

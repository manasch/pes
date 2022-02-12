#include<stdio.h>

int main(){
    /*
    char ch;
    while((ch=getchar()) != '\n'){
        //ch = getchar();
        putchar(ch);
    }
    int a = 5;
    printf("\n%d",++a);
    printf("\t%d",a);*/

    //printf("%d", 5 == 5 == 1);
    //int b = 20,*p;
    //p = &b;
    //printf("pointer to b : %p value \n", p, *p);
    /*
    int a=10;
    int b=a*a++;
    printf("%d",b);

    printf("10");*/

/*
    int n=5;
    int f = 1;
    while(--n){
        f*=n;
    }
    printf("%d",f);*/

    int *p;
    int a =10;
    p=&a;
    printf("%d\n",*p++);
}

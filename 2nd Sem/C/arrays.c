#include<stdio.h>

int main(){
    /*
    int b[5] = {[3] = 5};
    printf("%d\n",b[3]);
    for (int i=0;i<6;i++){
        printf("Enter a number: ");
        scanf("%d",&b[i]);
    }
    for (int i=0;i<5;i++){
        printf("%d ",b[i]);
    }

    int a[10];
    printf("%d",sizeof(a)/sizeof(int));
    printf("%d",&a);

    int a=10;
    int *p=&a;
    printf("%d\n",p);
    //printf("%d\n",*p);
    //printf("%d\n",*p+1);
    printf("%d\n",p+1);*/

    int a=10;
    int *p=&a;
    printf("%d\n",p);
    printf("%d\n",(char*)p+1);

}
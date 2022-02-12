#include<stdio.h>

int fib();
void main(){
    int n;
    printf("Enter range : ");
    scanf("%d",&n);
    fib(n);
}
int fib(int x){
    int y=1;
    for (int i=0, count =0;count<=x;count++){
        printf("%d\t",i);
        int temp = y;
        y+=i;
        i=temp;
    }
}

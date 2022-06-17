#include<stdio.h>
#include<math.h>

int armstrong(int);
int perfect(int);
int main(){
    int n;
    printf("Input any number: ");
    scanf("%d",&n);
    if (n == armstrong(n))
        printf("%d is an Armstrong number\n");
    if (n != armstrong(n))
        printf("%d is not an Armstrong number\n");
    if (n == perfect(n))
        printf("%d is a Perfect number\n");
    if (n != perfect(n))
        printf("%d is not a Perfect number\n");
    return 0;
}

int armstrong(int x){
    int sum = 0,t,len;
    for (t=x,len=0;t!=0; t/=10, len++);
    for (x;x!=0;x/=10)
       sum += pow((x%10), len);
    return sum;
}

int perfect(int x){
    int y=0;
    for (int i=1; i<x ; i++){
        if (x%i == 0)
            y+=i;
    }
    return y;
}
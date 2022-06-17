#include<stdio.h>

int prime(int);
int main(){
    int n,y;
    printf("Input a positive number: ");
    scanf("%d",&n);
    y = prime(n);
    if (y == 1)
        printf("%d is a prime number\n",n);
    else if (y == 0)
        printf("%d is not a prime number\n",n);
    else
        printf("Error\n");
}

int prime(int x){
    if (x == 2)
        return 1;
    else{
        for(int i=2;i<(x/2+1);i++){
            if (x%i==0)
                return 0;
            else
                return 1;
        }
    }
}
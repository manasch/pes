#include<stdio.h>

int series();
int fact();
void main(){
    int x;
    printf("Enter the number of terms: ");
    scanf("%d",&x);
    printf("Sum of the series is %d",series(x));
}
int fact(int x){
    int y = 1;
    if (x==0)
        return 1;
    else{
        for (int i=1;i<=x;i++)
            y*=i;
    }
    return y;
}
int series(int x){
    int sum;
    for (int i=1;i<=x;i++)
        sum+=fact(i)/i;
    return sum;
}
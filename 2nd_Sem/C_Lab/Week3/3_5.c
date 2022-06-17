#include<stdio.h>

int oct();
void main(){
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    printf("Octal of %d is %d",x,oct(x));
}
int oct(int x){
    int y;
    for (int i=1; x!=0; i*=10,x/=8)
        y += (x%8)*i;
    return y;
}
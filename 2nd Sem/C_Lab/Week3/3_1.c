#include<stdio.h>

int reverse(int);

int main(){
    int num,rev;
    printf("Enter the number: ");
    scanf("%d",&num);

    rev = reverse(num);
    if (rev==num)
        printf("The number %d is a palindrome\n",num);
    else
        printf("The number %d is not a palindrome\n",num);
}

int reverse(int x){
    int y=0;
    for(x;x!=0;x/=10)
        y = 10*y + x%10;
    
    return y;
}
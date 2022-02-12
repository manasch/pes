#include<stdio.h>
#include<math.h>

int main()
{
    int n,on,r,res=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    on = n;
    while (on!=0)
    {
        r = on % 10;
        res = res + pow(r,3);
        on = on/10;
    }
    if (n == res)
    {
        printf("%d is an armstrong number",n);
    }
    else
    {
        printf("%d is not an armstrong number",n);
    }
}
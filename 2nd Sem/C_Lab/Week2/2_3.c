#include<stdio.h>

int main()
{
    int i,j,r;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}


/*
int main()
{
    int n,i;
    printf("Enter the number to generate its multiplication table: ");
    scanf("%d",&n);
    for(i=1;i<=10;i++)
        printf("%d * %d = %d\n",n,i,n*i);
}
*/

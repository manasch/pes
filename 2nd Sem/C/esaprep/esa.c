#include<stdio.h>
#include<stdlib.h>

int main()
{
    char i = 0;
    int id;
    int price;
    int units;
    while(i < 10)
    {
        scanf("%d %d %d", &id, &price, &units);
        if(price < 10000)
        {
            int total = price*units;
            printf("Model %d total cost: %d\n", id, total);
        }
        i++;
    }
    return 0;
}
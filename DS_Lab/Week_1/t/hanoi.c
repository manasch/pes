#include <stdio.h>

void hanoi(int, char, char, char);

void main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
}

void hanoi(int disk, char start, char aux, char end)
{
    if (disk > 0)
    {
        hanoi(disk - 1, start, end, aux);
        printf("Move disk %d from rod %c to rod %c\n", disk, start, aux);
        hanoi(disk - 1, end, aux, start);
    }
}
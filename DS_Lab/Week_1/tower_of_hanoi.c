#include <stdio.h>
 
void hanoi(int, char, char, char);
 
int main()
{
    int num;
 
    printf("Enter the number of disks : ");
    scanf("%d", &num);

    hanoi(num, 'A', 'C', 'B');
    return 0;
}
void hanoi(int num, char start, char end, char aux)
{
    if (num == 1)
    {
        printf("\nMove disk 1 from rod %c to rod %c", start, end);
        return;
    }
    hanoi(num - 1, start, aux, end);
    printf("\nMove disk %d from rod %c to rod %c", num, start, end);
    hanoi(num - 1, aux, end, start);
}
#include<stdio.h>
#include<stdio.h>

// Tower of Hanoi
// n disks of different sizes, 3 pegs or towers Source : Temp : Destination
// smaller disks are always placed on the larger disks

// basic operation is the movement or move(), to compute and list down how many movements are required

void hanoi(int, char, char, char); // can be decalred inside main as well, then only main gets access to it

int main()
{
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
}

void hanoi(int n, char s, char t, char d) // start, temp, dest
{
    if (n == 1)
    {
        printf("\nMove disk %d from %c to %c", n, s, d);
        return;
    }
    
    hanoi(n - 1, s, d, t);
    printf("\nMove disk %d from %c to %c", n, s, d);
    hanoi(n - 1, t, s, d);
}
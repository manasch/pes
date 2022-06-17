#include <stdio.h>

typedef struct player
{
    char pname[100];
    char tname[100];
    int mat;
    int run;
} PLAYER;

void main()
{
    int n, max = 0, sum = 0;
    printf("Enter number of players: ");
    scanf("%d", &n);
    PLAYER *pl = (PLAYER *) malloc(n * sizeof(PLAYER));
    for (int i = 0; i < n; i++)
    {
        printf("For player %d\n", i + 1);
        printf("Enter player name: ");
        scanf("%s", pl[i].pname);
        printf("Enter team name: ");
        scanf("%s", pl[i].tname);
        printf("Enter no. of matches played: ");
        scanf("%d", &pl[i].mat);
        sum += pl[i].mat;
        printf("Enter no. of runs scored: ");
        scanf("%d", &pl[i].run);
    }
    for (int i = 1; i < n; i++)
    {
        if (pl[i].run > pl[max].run)
        {
            max = i;
        }
    }
    printf("Name\tTeam\tMatches\tRuns\n");
    printf("%s\t%s\t%d\t%d\n", pl[max].pname, pl[max].tname, pl[max].mat, pl[max].run);
    printf("Total number of matches: %d\n", sum);
}
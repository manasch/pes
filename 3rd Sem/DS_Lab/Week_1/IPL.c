#include<stdio.h>
#include<stdlib.h>

typedef struct match
{
    int match_no;
    int played;
    int score;
    int wickets;
}MATCH;

typedef struct player
{
    char name[20];
    char tname[20];
    MATCH m[14];
}PLAYER;

void accept_details(PLAYER *, int);
void find_max(PLAYER *, int, int);
void number_matches(PLAYER *, int);

int main()
{
    printf("\nEnter the number of players: ");
    int n;
    scanf("%d", &n);
    PLAYER p[n];

    accept_details(p, n);

    printf("\nEnter match number (1 - 14) to find maxmimum scoring player: ");
    int m_no;
    scanf("%d", &m_no);

    find_max(p, n, m_no);
    number_matches(p, n);

    return 0;
}

void accept_details(PLAYER *p, int n)
{
    printf("\nEnter the player details\n");
    for (int i = 0; i < n; i++){
        printf("\nEnter Player %d Name: ", i);
        scanf("%s", p[i].name);
        fflush(stdin);

        printf("Enter Player %d Team Name: ", i);
        scanf("%s", p[i].tname);
        fflush(stdin);

        for (int j = 0; j < 14; j++)
        {
            printf("\nEnter if Player %d has played match %d (1 or 0): ", i, j);
            scanf("%d", &p[i].m[j].played);
            fflush(stdin);
            p[i].m[j].match_no = j; //storing the match number


            if(p[i].m[j].played == 1)
            {
                printf("Enter Player %d's Score, Wickets Taken in Match %d: ", i, j);
                scanf("%d %d", &p[i].m[j].score, &p[i].m[j].wickets);
            }
            else
            {
                p[i].m[j].score = 0;
                p[i].m[j].wickets = 0;
            }
        }
    }
}

void find_max(PLAYER *p, int n, int m_no)
{
    int max = p[0].m[m_no].score;
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].m[m_no].score > max)
        {
            max = p[i].m[m_no].score;
            temp = i;
        }
    }
    printf("\nThe maximum runs; %d scored in match %d by Player:\n", max, m_no);
    printf("\nName: %s\nTeam Name: %s\nScore: %d\nWickets: %d\n", p[temp].name, p[temp].tname, 
    p[temp].m[m_no].score, p[temp].m[m_no].wickets);
}

void number_matches(PLAYER *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < 4; j++)
        {
            if (p[i].m[j].played == 1)
                count++;
        }

        printf("\nNumber of matches played by %s: %d", p[i].name, count);
    }
}
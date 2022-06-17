#include<stdio.h>
#include<string.h>

typedef struct cricket{
    char pname[20];
    char tname[20];
    float bavg;
}cricket;

int main(){
    cricket p[5], t;
    int n=5;
    float avg;

    printf("Enter the player data\n",n);
    for (int i=0;i<n;i++){
        printf("Enter the Player %d Name, Team Name and the Batting Average: ",i+1);
        scanf("%s %s %f",p[i].pname,p[i].tname,&avg);
        p[i].bavg = avg;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (strcmp(p[j-1].tname,p[j].tname)>0){
                t = p[j-1];
                p[j-1] = p[j];
                p[j] = t;
            }
        }
    }

    printf("\nPlayer list after sorting according to team");
    for (int i=0;i<n;i++){
        printf("\n%-20s %-20s %2.2f",p[i].pname,p[i].tname,p[i].bavg);
    }
    return 0;
}
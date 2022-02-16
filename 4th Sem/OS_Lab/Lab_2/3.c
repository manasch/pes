#include <stdio.h>

int main()
{
    int num, arrival[10];
    int burst[10], total = 0;
    int i, j, small, temp;
    int procs[100], k, wait[10], finish[10];
    float tavg, wavg;
    printf("Enter the number of jobs: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &burst[i]);
        wait[i] = 0;
        total += burst[i];
    }

    // sorting by arrival time
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (arrival[i] > arrival[j])
            {
                temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
    }

    for (i = 0; i < total; i++)
    {
        small = 3200;
        for (j = 0; j < num; j++)
        {
            if ((burst[j] != 0) && (arrival[j] <= i) && (burst[j] < small))
            {
                small = burst[j];
                k = j;
            }
        }
        burst[k]--;
        procs[i] = k;
    }

    k = 0;

    for (i = 0; i < total; i++)
    {
        for (j = 0; j < num; j++)
        {
            if (procs[i] == j)
            {
                finish[j] = i;
                wait[j]++;
            }
        }
    }

    printf("\nJob\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < num; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, finish[i], (finish[i] - arrival[i]) + 1, (((finish[i] + 1) - wait[i]) - arrival[i]));
        wavg = wavg + (((finish[i] + 1) - wait[i]) - arrival[i]);
        tavg = tavg + ((finish[i] - arrival[i]) + 1);
    }

    printf("\nAverage Waiting time: %lf", (wavg / num));
    printf("\nAverage Turnaround time: %lf\n", (tavg / num));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct tuple
{
    int pid;
    int burst_time;
} tuple;

void job_sort(int num, tuple *jobs)
{
    tuple temp;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (jobs[i].burst_time > jobs[j].burst_time)
            {
                temp.burst_time = jobs[i].burst_time;
                temp.pid = jobs[i].pid;

                jobs[i].burst_time = jobs[j].burst_time;
                jobs[i].pid = jobs[j].pid;

                jobs[j].burst_time = temp.burst_time;
                jobs[j].pid = temp.pid;
            }
        }
    }
}

int main()
{
	int num;
    int t1, t2;
	printf("Enter the number of jobs: ");
	scanf("%d", &num);

    tuple jobs[num];
	float wait_avg, turn_avg;
    int wait[num], turn[num];

	for (int i = 0; i < num; i++)
	{
		printf("Enter the burst time of process %d: ", i + 1);
		scanf("%d", &jobs[i].burst_time);
        jobs[i].pid = i;
	}

    job_sort(num, jobs);

    // calculating waittimes and turnaround times
	wait[0] = 0;
	for (int i = 1; i < num; i++)
	{
		wait[i] = jobs[i - 1].burst_time + wait[i - 1];
	}

	for (int i = 0; i < num; i++)
	{
		turn[i] = jobs[i].burst_time + wait[i];
	}

	// calculating averages
	for (int i = 0; i < num; i++)
	{
		t1 +=  wait[i];
		t2 +=  turn[i];
	}

	wait_avg = (float) t1 / num;
	turn_avg = (float) t2 / num;

	printf("\nJob\tBurst Time\tWaiting Time\tTurnaround Time\n");

	for (int i = 0; i < num; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, jobs[i].burst_time, wait[i], turn[i]);
	}

	printf("\nAverage waiting time: %lf", wait_avg);
	printf("\nAverage turn around time: %lf\n", turn_avg);

	return 0;
}

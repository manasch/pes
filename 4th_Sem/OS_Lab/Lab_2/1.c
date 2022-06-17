#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("Enter the number of jobs: ");
	scanf("%d", &num);

	int burst[num];
	int t1, t2;
	int wait[num];
	int turn[num];
	float wait_avg, turn_avg;

	for (int i = 0; i < num; i++)
	{
		printf("Enter the burst time of process %d: ", i + 1);
		scanf("%d", &burst[i]);
	}

	// calculating waittimes and turnaround times
	wait[0] = 0;
	for (int i = 1; i < num; i++)
	{
		wait[i] = burst[i - 1] + wait[i - 1];
	}

	for (int i = 0; i < num; i++)
	{
		turn[i] = burst[i] + wait[i];
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
		printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst[i], wait[i], turn[i]);
	}

	printf("\nAverage waiting time: %lf", wait_avg);
	printf("\nAverage turn around time: %lf\n", turn_avg);

	return 0;
}
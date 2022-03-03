#include <stdio.h>
#include <time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);
	t += (end.tv_sec - start.tv_sec) * 0.000000001;
	return t;
}

int main()
{
	long int s = 0;
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_REALTIME, &start);
	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 1; j < 10000; j++)
		{
			++s;
		}
	}
	clock_gettime(CLOCK_REALTIME, &end);
	printf("time %lf\n", time_elapsed(start, end));
	printf("s : %ld\n", s);
}
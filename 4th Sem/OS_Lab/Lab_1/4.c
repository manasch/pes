#include <stdio.h>
#include <unistd.h>

int main()
{
	int p1 = fork();

	if (p1 < 0)
	{
		printf("Failed to create a child process\n");
	}
	else if (p1 == 0)
	{
		printf("Child process ID: %d\n", getpid());
		printf("Child parent process ID: %d\n", getppid());

		sleep(3);
		int p2 = fork();
		
		if (p2 < 0)
		{
			printf("Failed to create a child process\n");
		}
		else if (p2 == 0)
		{
			printf("Child process ID: %d\n", getpid());
			printf("Child parent process ID: %d\n", getppid());
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				printf("Iteration %d in child process\n", i + 1);
				sleep(2);
			}
		}
	}
	else
	{
		printf("Parent process ID: %d\n", getpid());
	}

	return 0;
}

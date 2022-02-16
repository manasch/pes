#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int a = 5; // global variable

int main()
{
	int pid = fork();
	int b = 10;

	printf("Initial values:\na: %d, b: %d\n", a, b);

	if (pid < 0)
		printf("Failure to create child process\n");
	else if (pid == 0)
	{
		printf("Inside child process\n");
		a = a + 5;
		b = b - 5;
		printf("a: %d, b: %d\n", a, b);
	}
	else
	{
		wait(NULL);
		printf("Inside parent process\n");
		a = a * 5;
		b = b + 20;
		printf("a: %d, b: %d\n", a, b);
	}

	return 0;
}

	

	

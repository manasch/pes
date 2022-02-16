#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();

	if (pid < 0)
		printf("Failed to create child process\n");
	else if (pid == 0)
	{
		printf("Child process\n");

		char * const args[] = {"./findsum.out", "5", "10", "25", NULL};
		char * const env[] = {NULL};
		execve(args[0], args, env);
	}
	else
	{
		wait(NULL);
		printf("Parent process\n");
	}

	return 0;
}

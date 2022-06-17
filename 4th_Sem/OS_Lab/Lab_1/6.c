#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();
	if (pid < 0)
	{
		printf("Failed to create child process\n");
		exit(1);
	}
	else if (pid == 0)
	{
		printf("Inside child process\n");
		execl("/bin/ls", "ls", "-la", NULL);
		printf("After exec run\n");
	}
	else
	{
		wait(NULL);
		printf("Inside parent process\n");
	}

	return 0;
}

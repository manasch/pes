#include <stdio.h>
#include <unistd.h>

int main() {
	int pid = fork();

	if (pid < 0)
	{
		printf("Failed to create a child process\n");
	}
	else if (pid == 0)
	{
		printf("Process ID of child process observed from child process: %d\n", getpid());
		printf("Process ID of parent process observed from child process: %d\n", getppid());
	}
	else
	{
		printf("Process ID of child process observed from parent process: %d\n", pid);
		printf("Process ID of parent process observed from parent process: %d\n", getpid());

	}

	return 0;
}

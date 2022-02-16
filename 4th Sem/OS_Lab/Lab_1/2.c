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
		printf("Child process running\n");
	}
	else
	{
		printf("Parent process running\n");
	}

	return 0;
}

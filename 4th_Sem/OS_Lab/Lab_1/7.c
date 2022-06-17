#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();

	if (pid < 0)
	{
		printf("Failed to create child process\n");
	}
	else if (pid == 0)
	{
		printf("Inside child process\n");
		char * const args[] = {"/bin/touch", "abc.txt", NULL};
		char * const env[] = {NULL};
		execve(args[0], args, env);
	}
	else
	{
		wait(NULL);
		printf("Back to parent process after blocking\n");

		execl("/bin/ls", "ls", "-la", "./", NULL);
	}

	return 0;
}
	
	

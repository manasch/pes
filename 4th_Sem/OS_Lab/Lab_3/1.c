#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg[BUFFER_SIZE] = "";

	int fd[2];
	pid_t pid;
	// create a pipe
	if (pipe(fd) == -1)
	{
		printf("\nPipe failes\n");
		return 1;
	}
	
	// fork a child process
	pid = fork();
	if (pid > 0) // parent process
	{
		// close unused end of the pope
		close(fd[READ_END]);
		// write to the pipe
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
		// close the write at the end of pipe
		close(fd[WRITE_END]);
		wait(NULL);
	}
	else if (pid == 0) //child process
	{
		close(fd[WRITE_END]);
		// read from the pipe
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("Child process read: %s\n", read_msg);

		close(fd[READ_END]);
	}
	else
	{
		printf("Fork failure\n");
		return 1;
	}
}

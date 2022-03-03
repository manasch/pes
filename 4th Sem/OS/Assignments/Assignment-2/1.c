/* Implement pipe operator in  with the following functionality:
 - The server process reads the output from the pipe
 - The client process must write the contents to a pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define BUFFER_SIZE 20

int main()
{
    int pid;
    int fd[2];

    // create a pipe
    if (pipe(fd) == -1)
    {
        printf("\nPipe creation failed");
        return 1;
    }

    pid = fork();
    if (pid < 0)
    {
        printf("\nFork failure");
    }
    // child process is the server
    else if (pid == 0)
    {
        char readmsg[BUFFER_SIZE];
        close(fd[1]);
        read(fd[0], readmsg, BUFFER_SIZE);
        printf("\nServer reads: %s\n", readmsg);
    }
    // parent process is the client
    else
    {
        close(fd[0]);
        char input[BUFFER_SIZE];
        printf("\nEnter string: ");
        scanf("%s", input);
        write(fd[1], input, BUFFER_SIZE);
        close(fd[1]);
        wait(NULL);
    }
}
/* Using pipes, find the sum of an array as follows:
 - One process calculates the sum of half of the array and stores it in the pipe
 - The second process calculates the sum of the other half, reads the sum on the pipe and returns the total sum
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define ARR_SIZE 10

int SUM_ARRAY[ARR_SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

int find_sum(int start, int end)
{
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += SUM_ARRAY[i];
    }
    return sum;
}

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
    // child process is the server, calculates second half of the sum
    else if (pid == 0)
    {
        int sum2 = 0, child_sum = 0, final_sum = 0;
        close(fd[1]);
        sum2 = find_sum(ARR_SIZE / 2, ARR_SIZE);
        read(fd[0], &child_sum, sizeof(sum2));
        printf("\nHalf sum in client: %d", child_sum);
        printf("\nHalf sum in server: %d", sum2);
        final_sum = child_sum + sum2;
        printf("\nThe final sum of all elements is: %d\n", final_sum);
        close(fd[0]);
    }
    // parent process is the client, calculates first half of the sum
    else
    {
        int sum1 = 0;
        close(fd[0]);
        sum1 = find_sum(0, ARR_SIZE / 2);
        write(fd[1], &sum1, sizeof(sum1));
        close(fd[1]);
        wait(NULL);
    }
}
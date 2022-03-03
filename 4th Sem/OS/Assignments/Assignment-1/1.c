#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid < 0)
    {
        printf("Failed to fork the process..\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Entered the child process\n");
        execl("/bin/mkdir", "mkdir", "newdir", NULL);
        printf("Created the new directory\n");
    }
    else
    {
        printf("Entered the parent process\n");
        wait(NULL);
        printf("After the child process\n");
        execl("/bin/touch", "touch", "./newdir/newfile.txt", NULL);
    }

    return 0;
}

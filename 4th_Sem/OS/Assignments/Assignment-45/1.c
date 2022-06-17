/*
    Write a C program to change the ownership of files in a directory created after a certain date.
    Inputs to the program: directory, date and new permission to be set as run time arguments
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int mode;
    struct dirent *dp;
    struct stat info;
    char date[20];
    char directory_buffer[50];

    printf("\nEnter the directory name: ");
    scanf("%s", directory_buffer);

    DIR *dir = opendir(directory_buffer);

    if (!dir)
    {
        printf("\nUnable to open the directory");
        return 0;
    }

    printf("Enter the date [dd/mm/yyyy]: ");
    scanf("%s", date);

    printf("Enter the access mode (4-digits): ");
    scanf("%d", &mode);

    while ((dp = readdir(dir)) != NULL)
    {
        stat(dp->d_name, &info);

        if (strcmp(date, ctime(&info.st_ctime)) <= 0)
        {
            printf("\nBefore:\n%s Owner: %d, Group: %d", dp->d_name, info.st_uid, info.st_gid);
            chown(dp->d_name, mode, 1001);
            stat(dp->d_name, &info);
            printf("\nAfter:\n%s Owner: %d, Group: %d", dp->d_name, info.st_uid, info.st_gid);
        }
    }

    closedir(dir);

    return 0;
}

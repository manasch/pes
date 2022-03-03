// Write a C program to list all files that have been modified after a certain date.
// Inputs to the program: directory and date

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    struct dirent *dp;
    struct stat buf;
    struct tm t;
    time_t input_date;
    if (argc != 5)
    {
        printf("Usage: a.out <directory> <date>\n");
        exit(0);
    }

    DIR *dir = opendir(argv[1]);
    if (!dir)
    {
        printf("Unable to open the directory\n");
        return 0;
    }

    // Converting the input date to epoch time
    int day = atoi(argv[2]);
    int month = atoi(argv[3]);
    int year = atoi(argv[4]);
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;
    input_date = mktime(&t);

    printf("Listing files after %d-%d-%d\n", day, month, year);

    while ((dp = readdir(dir)) != NULL)
    {
        if (lstat(dp->d_name, &buf) < 0)
        {
            printf("lstat error\n");
            continue;
        }
        long int creation_time = buf.st_mtime;
        if (creation_time > input_date)
            printf("File: %s\n", dp->d_name);
    }

    closedir(dir);

    return 0;
}

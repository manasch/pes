#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int arr[8] = {1, 6, 2, 4, 5, 8, 9, 0};

void sort(int choice, int n)
{
    if (choice == 1) // uses descending order
    {
        for (int i = 0; i < (n - 1); i++)
        {
            int pos = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[pos] > arr[j])
                    pos = j;
            }

            if (pos != i)
            {
                int temp = arr[i];
                arr[i] = arr[pos];
                arr[pos] = temp;
            }
        }
    }
    else // uses ascending order
    {
        for (int i = 0; i < (n - 1); i++)
        {
            int pos = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[pos] < arr[j])
                    pos = j;
            }

            if (pos != i)
            {
                int temp = arr[i];
                arr[i] = arr[pos];
                arr[pos] = temp;
            }
        }
    }
}

void print_array(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main()
{
    printf("Original array:\n");
    print_array(8);
    int pid = fork();

    if (pid < 0)
    {
        printf("Failed to fork the process..\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Entered the child process\n");
        sort(1, 8);
        printf("\nArray sorted in descending order:\n");
        print_array(8);
    }
    else
    {
        printf("Entered the parent process\n");
        wait(NULL);
        printf("After the child process\n");
        sort(0, 8);
        printf("\nArray sorted in ascending order:\n");
        print_array(8);
    }

    return 0;
}

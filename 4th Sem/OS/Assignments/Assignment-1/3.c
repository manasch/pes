#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char string1[25] = "HELLO ";
    char string2[25] = "WORLD";

    printf("First string: %s\n", string1);
    printf("Second string: %s\n", string2);

    strcat(string1, string2);

    char * const args[] = {"./printstring.out", string1, NULL};
    char * const env[] = {NULL};
    execve(args[0], args, env);

    return 0;
}

// Unable to include the file in google form
// printstring.c file
// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[])
// {
//     printf("\nInside printstring function\n");
//     printf("The concatenated string is: ");
//     printf("%s\n", argv[1]);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("\nInside printstring function\n");
    printf("The concatenated string is: ");
    printf("%s\n", argv[1]);
    return 0;
}

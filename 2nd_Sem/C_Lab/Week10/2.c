#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *source, *target;
    int ch;
    
    if(argc != 3)
    {
        printf("\nInvalid number of arguements\n");
        return 1;
    }

    source = fopen(argv[1], "r");
    if(source == NULL)
    {
        printf("\nSource file could not be opened\n");
        return 1;
    }

    target = fopen(argv[2], "w");
    if(target == NULL)
    {
        printf("\nTarget file could not be opened\n");
        fclose(source);
        return 1;
    }
    while(1)
    {
        ch = fgetc(source);
        if(feof(source))
            break;
        fputc(ch, target);
    }
    fclose(source);
    fclose(target);

    return 0;
}

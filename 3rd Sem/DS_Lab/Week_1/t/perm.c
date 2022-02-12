#include <stdio.h>
#include <string.h>
 
void swap(char *a, char *b);
void perm(char *str, int start, int end);

 
int main()
{
    char str[10] = "pes";
    int n = strlen(str);
    perm(str, 0, n-1);
    return 0;
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void perm(char *str, int start, int end)
{

    if (start == end)
        printf("%s\n", str);
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap((str + start), (str + end));
            perm(str, start + 1, end);
            swap((str + start), (str + i));
        }
    }
}

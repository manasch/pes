#include <stdio.h>

int search(char *str, char* substr)
{
    int i = 0, j = 0;
    
    if (str[0] == '\0')
    {
        return 0;
    }
    if (substr[0] == '\0')
    {
        return 1;
    }
    if (str[0] == substr[0])
    {
        return search(str + 1, substr + 1);
    }
    return search(str + 1, substr);
}

void main()
{
    char a[20] = "apple tree", b[10] = "apple", c[10] = "orange";
    
    printf("%d\n", search(a, b));
    printf("%d\n", search(a, c));
    printf("%d\n", search(a, c));
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void prefixFunction(int m, char *p, int *prefixTable) {
    prefixTable[1] = 0;
    int k = 0;
    for (int i = 2; i <= m; i++) {
        while (k > 0 && p[k + 1] != p[i])
            k = prefixTable[k];
        
        if (p[k + 1] == p[i])
            ++k;
        prefixTable[i] = k; 
    }
}

void main() {
    int n, m;
    scanf("%d %d\n", &n, &m);

    if (m > n) {
        printf("%d", 0);
        return;
    }

    char text[n + 1];
    char pattern[m + 1];
    int prefixTable[m + 1];
    prefixTable[0] = 0;

    scanf("%[^\n]s", text + 1);
    scanf("%s", pattern + 1);

    // Building the prefix table
    prefixFunction(m, pattern, prefixTable);

    int j = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        while (j > 0 && pattern[j + 1] != text[i])
            j = prefixTable[j];
        
        if (pattern[j + 1] == text[i])
            ++j;
        
        if (j == m) {
            printf("%d", i - m + 1);
            flag = true;
            break;
        }
    }

    if (!flag)
        printf("%d", 0);
    return;
}

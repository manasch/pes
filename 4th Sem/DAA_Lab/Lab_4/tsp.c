#include <stdio.h>
#include <stdlib.h>

// https://www.baeldung.com/wp-content/uploads/sites/4/2020/10/1-3.png for the graph
// Weighted matrix
/*
        A   B   C   D   E
        0   1   2   3   4
--------------------------------
A   0   0   12  10  19  8
B   1       0   3   7   6
C   2           0   2   20
D   3               0   4
E   4                   0
*/

// adjMatrix[i][j] has weight of the edge (i,j), which is a +ve int
// Version 1: The graph is a undirected complete graph
// Version 2: The graph is a directed graph, not necessarily complete
// adjMatrix[i][j] = 0 for missing edges

int tsp(int n , int **adjMatrix);
void printMatrix(int n , int **adjMatrix);


int main()
{
    int n;
    scanf("%d", &n);
    int **adjMatrix = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adjMatrix[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    
    printMatrix(n, adjMatrix);
    printf("Shortest roundtrip: %d\n", tsp(n, adjMatrix));
    return 0;

}

int tsp(int n, int **adjMatrix)
{
    return 0;
}

int permutations(int n, int **adjMatrix)
{
    
}

void printMatrix(int n , int **adjMatrix)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", adjMatrix[i][0]);
        for(int j = 1; j < n; j++)
        {
            printf(" %d", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

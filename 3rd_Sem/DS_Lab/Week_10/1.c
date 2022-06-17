// Write a program to check the connectivity of a graph using DFS (Recursion). Also compute the number of components of a graph

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

typedef struct graph
{
    int n;
    int adj[MAX_NODES][MAX_NODES];
} graph;

void create_graph(graph *);
void display(graph *);
int indegree(graph *, int);
int outdegree(graph *, int);
void dfs(graph *);
void dfs_help(graph *, int, int *);

int main()
{
    graph adj_matrix;
    int ch, v, i;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &adj_matrix.n);

    create_graph(&adj_matrix);

    while (1)
    {
        printf("\n1) Indegree");
        printf("\n2) Outdegree");
        printf("\n3) Display matrix");
        printf("\n4) Traversal (DFS)");
        printf("\n5) Exit");
        printf("\nChoice: ");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the vertex: ");
            scanf("%d", &v);
            i = indegree(&adj_matrix, v);
            printf("\nIndegree of %d: %d\n", v, i);
            break;

        case 2:
            printf("\nEnter the vertex: ");
            scanf("%d", &v);
            i = outdegree(&adj_matrix, v);
            printf("\nOutdegree of %d: %d\n", v, i);
            break;

        case 3:
            display(&adj_matrix);
            break;

        case 4:
            dfs(&adj_matrix);
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}

void create_graph(graph *adj_mat)
{
    int i, j;
    for (i = 0; i < adj_mat->n; i++) // initializing all of it to 0
    {
        for (j = 0; j <= adj_mat->n; j++)
        {
            adj_mat->adj[i][j] = 0;
        }
    }

    while (1)
    {
        printf("\nEnter source and destination vertices: ");
        scanf("%d %d", &i, &j);

        if (i < 0 && j < 0 || i >= adj_mat->n || j >= adj_mat->n) // out of bounds
            break;
        
        adj_mat->adj[i][j] = 1;
    }
}

int indegree(graph *adj_mat, int v)
{
    int count = 0;
    for (int i = 0; i < adj_mat->n; i++)
    {
        if (adj_mat->adj[i][v] == 1)
        {
            count++;
        }
    }
    return count;
}

int outdegree(graph *adj_mat, int v)
{
    int count = 0;
    for (int j = 0; j < adj_mat->n; j++)
    {
        if (adj_mat->adj[v][j] == 1)
        {
            count++;
        }
    }
    return count;
}

void display(graph *adj_mat)
{
    for (int i = 0; i < adj_mat->n; i++)
    {
        for (int j = 0; j < adj_mat->n; j++)
        {
            printf("%d ", adj_mat->adj[i][j]);
        }
        printf("\n");
    }   
}

void dfs(graph *adj_mat)
{
    int vertex;
    int *visited;

    printf("\nEnter the source vertex: ");
    scanf("%d", &vertex);

    if (vertex < 0 || vertex >= adj_mat->n)
    {
        printf("Vertex not in graph");
        free(visited);
        return;
    }

    visited = (int *) calloc(adj_mat->n, sizeof(int));

    dfs_help(adj_mat, vertex, visited);

    printf("\n");
}

void dfs_help(graph *adj_mat, int vertex, int *visited)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < adj_mat->n; i++)
    {
        if (adj_mat->adj[vertex][i] == 1 && visited[i] == 0)
        {
            dfs_help(adj_mat, i, visited);
        }
    }
}
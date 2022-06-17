// Write a program traverse the graph using BFS traversal technique. Use the explicit queue for implementation

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
void append(int *, int, int *);
void bfs(graph *);
int delete(int *, int *);

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
        printf("\n4) Traversal (BFS)");
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
            bfs(&adj_matrix);
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid choice");
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
        for (j = 0; j < adj_mat->n; j++)
        {
            adj_mat->adj[i][j] = 0;
        }
    }

    while (1)
    {
        printf("\nEnter source and destination vertices: ");
        scanf("%d %d", &i, &j);

        if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n) // out of bounds
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

void bfs(graph *adj_mat)
{
    int vertex, qr = -1;
    int *visited, *queue;

    // User input
    printf("\nEnter source vertex: ");
    scanf("%d", &vertex);

    // out of bounds
    if (vertex < 0 || vertex >= adj_mat->n)
    {
        printf("\nVertext not in the graph");
        return;
    }

    visited = (int *) calloc(adj_mat->n, sizeof(int));
    queue = (int *) calloc(adj_mat->n, sizeof(int));

    append(queue, vertex, &qr);
    visited[vertex] = 1;

    while (qr != -1)
    {
        vertex = delete(queue, &qr);
        printf("%d ", vertex);
        for (int i = 0; i < adj_mat->n; i++)
        {
            if (adj_mat->adj[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                append(queue, i, &qr);
            }
        }
    }

    free(visited);
    free(queue);
}

void append(int *queue, int v, int *pqr)
{
    ++(*pqr);
    queue[*pqr] = v;
}

int delete(int *queue, int *pqr)
{
    int res = queue[0];
    
    for (int i = 0; i < *pqr; i++)
    {
        queue[i] = queue[i + 1];
    }

    --(*pqr);
    return res;
}
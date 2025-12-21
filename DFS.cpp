#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int n;
void dfs(int node)
{
    int i;
    visited[node] = 1;
    printf("%d ", node + 1);
    for (i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}
void displayMatrix()
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i, j, edge, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    printf("\nEnter edges (1 = Yes, 0 = No):\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("Is there an edge between %d and %d? ", i + 1, j + 1);
            scanf("%d", &edge);

            if (edge == 1)
            {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
    displayMatrix();
    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &start);
    printf("\nDFS Traversal: ");
    dfs(start - 1);
    printf("\n");
    return 0;
}


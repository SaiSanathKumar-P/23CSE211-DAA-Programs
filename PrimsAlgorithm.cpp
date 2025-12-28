#include <stdio.h>
#include <limits.h>
#define V 5
int findMinKey(int key[], int mst[])
{
    int min = INT_MAX;
    int minIndex = -1;
    int i;

    for (i = 0; i < V; i++)
    {
        if (mst[i] == 0 && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void primsAlgorithm(int graph[V][V])
{
    int parent[V];   
    int key[V];     
    int mst[V];     
    int i, j, u;
    for (i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[0] = 0;  
    parent[0] = -1; 
    for (i = 0; i < V - 1; i++)
    {
        u = findMinKey(key, mst);
        mst[u] = 1;

        for (j = 0; j < V; j++)
        {
            if (graph[u][j] != 0 && mst[j] == 0 && graph[u][j] < key[j])
            {
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main()
{
    int graph[V][V] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primsAlgorithm(graph);

    return 0;
}


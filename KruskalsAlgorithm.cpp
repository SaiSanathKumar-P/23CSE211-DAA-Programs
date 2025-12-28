#include <stdio.h>
#include <stdlib.h>

#define V 5     
#define E 7    

struct Edge
{
    int u;
    int v;
    int weight;
};

int findParent(int parent[], int vertex)
{
    if (parent[vertex] == -1)
        return vertex;

    return findParent(parent, parent[vertex]);
}

void unionSet(int parent[], int x, int y)
{
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);

    parent[xRoot] = yRoot;
}

int compareEdges(const void *a, const void *b)
{
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;

    return e1->weight - e2->weight;
}

void kruskalAlgorithm(struct Edge edges[])
{
    int parent[V];
    int i;
    int totalWeight = 0;

    for (i = 0; i < V; i++)
    {
        parent[i] = -1;
    }

    qsort(edges, E, sizeof(struct Edge), compareEdges);

    printf("Edge \tWeight\n");

    for (i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        int x = findParent(parent, u);
        int y = findParent(parent, v);

        if (x != y)
        {
            printf("%d - %d \t%d\n", u, v, w);
            totalWeight = totalWeight + w;
            unionSet(parent, x, y);
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

int main()
{
    struct Edge edges[E] =
    {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 4, 5},
        {2, 4, 7},
        {2, 3, 8},
        {3, 4, 9}
    };

    kruskalAlgorithm(edges);

    return 0;
}


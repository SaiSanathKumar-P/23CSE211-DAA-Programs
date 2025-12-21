#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0;
int rear = -1;
int n;
void enqueue(int value)
{
    rear = rear + 1;
    queue[rear] = value;
}
int dequeue()
{
    int value;
    value = queue[front];
    front = front + 1;
    return value;
}
void bfs(int start)
{
    int current, i;
    visited[start] = 1;
    enqueue(start);
    printf("\nBFS Traversal: ");
    while (front <= rear)
    {
        current = dequeue();
        printf("%d ", current + 1);
        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
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
    printf("\nEnter starting vertex: ");
    scanf("%d", &start);
    bfs(start - 1);
    return 0;
}

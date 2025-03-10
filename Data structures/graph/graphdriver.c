#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
void DFS(int G[][7], int src, int visited[])
{
    printf("%d  ", src);
    visited[src] = 1;
    for (int j = 0; j < 7; j++)
    {
        int dest = G[src][j];
        if (dest == 1 && visited[j] != 1)
        {
            DFS(G, j, visited);
        }
    }
}
void BFS(int G[][7], int src, int visited[])
{
    struct Queue cqu;
    createQueue(&cqu, 20);
    enqueue(&cqu, src);
    while (!(cqu.front == -1 && cqu.back == -1))
    {
        src = dequeue(&cqu);
        if (visited[src] != 1)
            printf("%d  ", src);
        visited[src] = 1;
        for (int j = 0; j < 7; j++)
        {
            int dest = G[src][j];
            if (dest == 1 && visited[j] != 1)
            {
                enqueue(&cqu, j);
            }
        }
    }
}

int main()
{
    int v = 7;
    int G[7][7] = {{0, 1, 1, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0}};
    int visited[7] = {0};
    int src = 0;
    DFS(G, src, visited);
    printf("\n");
    int visit[7] = {0};
    BFS(G, src, visit);
    return 0;
}

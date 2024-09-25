#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

int minDistance(int dist[], bool vis[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!vis[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool vis[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        vis[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, vis);
        vis[u] = true;

        for (int v = 0; v < V; v++) {
            if (!vis[v] && graph[u][v]) {
                if (dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] = { { 0, 10, 0, 0, 3 },
                        { 10, 0, 2, 0, 7 },
                        { 0, 2, 0, 9, 0 },
                        { 0, 0, 9, 0, 4 },
                        { 3, 7, 0, 4, 0 } };

    dijkstra(graph, 0);

    return 0;
}

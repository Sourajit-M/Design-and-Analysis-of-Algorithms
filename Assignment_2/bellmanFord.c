#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int src;
    int dest;
    int wt;
} Edge;

void bellmanFord(Edge* graph, int V, int E, int src) {
    int* dist = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[graph[j].src] != INT_MAX && dist[graph[j].src] + graph[j].wt < dist[graph[j].dest]) {
                dist[graph[j].dest] = dist[graph[j].src] + graph[j].wt;
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }

    free(dist);
}

int main() {
    int V = 5;
    int E = 8;

    Edge* graph = (Edge*)malloc(E * sizeof(Edge));

    graph[0].src = 0; graph[0].dest = 1; graph[0].wt = -1;
    graph[1].src = 0; graph[1].dest = 2; graph[1].wt = 4;
    graph[2].src = 1; graph[2].dest = 2; graph[2].wt = 3;
    graph[3].src = 1; graph[3].dest = 3; graph[3].wt = 2;
    graph[4].src = 1; graph[4].dest = 4; graph[4].wt = 2;
    graph[5].src = 3; graph[5].dest = 2; graph[5].wt = 5;
    graph[6].src = 3; graph[6].dest = 1; graph[6].wt = 1;
    graph[7].src = 4; graph[7].dest = 3; graph[7].wt = -3;

    bellmanFord(graph, V, E, 0);

    return 0;
}

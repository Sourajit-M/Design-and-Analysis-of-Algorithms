#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX 100

int dfs(int rGraph[MAX][MAX], int source, int sink, int parent[], int V) {
    int visited[MAX] = {0};
    int stack[MAX], top = -1;

    stack[++top] = source;
    visited[source] = 1;
    parent[source] = -1;

    while (top >= 0) {
        int u = stack[top--];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                stack[++top] = v;
                parent[v] = u;
                visited[v] = 1;

                if (v == sink)
                    return 1;
            }
        }
    }
    return 0;
}

int fordFulkerson(int graph[MAX][MAX], int source, int sink, int V) {
    int rGraph[MAX][MAX], u, v;

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[MAX];
    int max_flow = 0;

    while (dfs(rGraph, source, sink, parent, V)) {
        int path_flow = INT_MAX;


        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            path_flow = (path_flow < rGraph[u][v]) ? path_flow : rGraph[u][v];
        }

        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int V, graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int source, sink;
    printf("Enter the source and sink vertices: ");
    scanf("%d %d", &source, &sink);

    printf("The maximum possible flow is: %d\n", fordFulkerson(graph, source, sink, V));

    return 0;
}

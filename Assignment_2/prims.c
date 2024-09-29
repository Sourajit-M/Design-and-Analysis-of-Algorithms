#include <stdio.h>
#include <limits.h>
#define N 100

int minKey(int key[], int mst[], int vertices) {
    int min = INT_MAX, minIndex;

    for (int i = 0; i < vertices; i++) {
        if (!mst[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printMST(int parent[], int graph[N][N], int vertices) {
    printf("Edge \tWeight\n");
    int cost  = 0;
    for (int i = 1; i < vertices; i++) {
        cost += graph[i][parent[i]];
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }

    printf("Minimum Cost of Spanning Tree : %d", cost);
}

void primMST(int graph[N][N], int vertices) {
    int parent[N];
    int key[N];  
    int mstSet[N];

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);

        mstSet[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, vertices);
}

int main() {
    int vertices;

    printf("Input the number of vertices: ");
    scanf("%d", &vertices);

    int graph[N][N];

    printf("Input graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, vertices);

    return 0;
}

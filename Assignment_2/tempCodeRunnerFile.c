#include <stdio.h>
#include <limits.h>

#define N 100


int minKey(int key[], int mst[], int v) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < v; v++) {
        if (!mst[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int parent[], int graph[N][N], int v) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < v; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}


void primMST(int graph[N][N], int v) {
    int parent[N];
    int key[N];  
    int mst[N];

    for (int i = 0; i < v; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < v - 1; count++) {
        int u = minKey(key, mst, v);

        mst[u] = 1;
        for (int v = 0; v < v; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, v);
}

int main() {
    int v;

    printf("Input the number of v: ");
    scanf("%d", &v);

    if (v <= 0 || v > N) {
        printf("Invalid number of v. Exiting...\n");
        return 1;
    }

    int graph[N][N];

    printf("Input the adjacency matrix for the graph:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, v);

    return 0;
}

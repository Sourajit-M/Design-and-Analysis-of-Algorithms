#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src;
    int dest;
    int wt;
} Edge;

int* parent;
int* rank;

void init(int V) {
    parent = (int*)malloc(V * sizeof(int));
    rank = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int node) {
    if (parent[node] != node) {
        parent[node] = find(parent[node]);
    }
    return parent[node];
}

void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->wt - ((Edge*)b)->wt;
}

void kruskalsMST(Edge* edges, int E, int V) {
    init(V);
    qsort(edges, E, sizeof(Edge), compareEdges);
    
    int ans = 0;
    int count = 0;

    for (int i = 0; count < V - 1; i++) {
        Edge e = edges[i];
        
        int parA = find(e.src);
        int parB = find(e.dest);
        
        if (parA != parB) {
            unionSets(e.src, e.dest);
            ans += e.wt;
            count++;
        }
    }
    printf("MST cost = %d\n", ans);
    free(parent);
    free(rank);
}

int main() {
    int V = 5;
    int E = 7;

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));

    edges[0] = (Edge){0, 1, 10};
    edges[1] = (Edge){0, 2, 6};
    edges[2] = (Edge){0, 3, 5};
    edges[3] = (Edge){1, 3, 15};
    edges[4] = (Edge){2, 3, 4};
    edges[5] = (Edge){1, 2, 5};
    edges[6] = (Edge){2, 4, 9};

    kruskalsMST(edges, E, V);

    free(edges);
    return 0;
}

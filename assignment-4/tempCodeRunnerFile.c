#include <stdio.h>
#include <limits.h>

#define n 4

int min(int a, int b) {
    return a < b ? a : b;
}

int findMinEdge(int dist[n][n], int i) {
    int minEdge = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (i != j) {
            minEdge = min(minEdge, dist[i][j]);
        }
    }
    return minEdge;
}

int calc(int dist[n][n]) {
    int bound = 0;
    for (int i = 0; i < n; i++) {
        bound += findMinEdge(dist, i);
    }
    return bound / 2;
}

void tsp(int dist[n][n], int vis[n], int currCost, int bound, int level, int currPath[], int res[], int* minCost) {
    if (level == n) {
        int total = currCost + dist[currPath[level-1]][currPath[0]];
        if (total < *minCost) {
            *minCost = total;
            for (int i = 0; i < n; i++) {
                res[i] = currPath[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int tempBound = bound;
            vis[i] = 1;
            currPath[level] = i;

            int newCost = currCost + dist[currPath[level - 1]][i];
            tempBound -= findMinEdge(dist, currPath[level - 1]);

            if (newCost + tempBound < *minCost) {
                tsp(dist, vis, newCost, tempBound, level + 1, currPath, res, minCost);
            }

            vis[i] = 0;
        }
    }
}


int main() {
    int dist[n][n] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
    };

    int vis[n] = {0};
    int currPath[n + 1];
    int res[n];
    int minCost = INT_MAX;

    int initialBound = calc(dist);

    vis[0] = 1;
    currPath[0] = 0;

    tsp(dist, vis, 0, initialBound, 1, currPath, res, &minCost);

    printf("Minimum cost: %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    printf("0\n");

    return 0;
}

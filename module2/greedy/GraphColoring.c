#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void colorGraph(int graph[MAX][MAX], int V, int color[MAX]) {
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    for (int vertex = 0; vertex < V; vertex++) {
        int neighborColors[MAX] = {0};

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (graph[vertex][neighbor] == 1 && color[neighbor] != 0) {
                neighborColors[color[neighbor]] = 1;
            }
        }

        int assignedColor = 1;
        while (neighborColors[assignedColor] == 1) {
            assignedColor++;
        }

        color[vertex] = assignedColor;
    }
}

int main() {
    // int graph[MAX][MAX] = {
    //     {0, 1, 1, 0, 0, 0},
    //     {1, 0, 1, 0, 0, 0},
    //     {1, 1, 0, 1, 1, 1},
    //     {0, 0, 1, 0, 1, 0},
    //     {0, 0, 1, 1, 0, 1},
    //     {0, 0, 1, 0, 1, 0}
    // };

    int graph[MAX][MAX] = {
        {0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    
    int V = 6;

    int color[MAX];

    colorGraph(graph, V, color);

    printf("Node colors:\n");
    int maxColor = 0;
    for (int i = 0; i < V; i++) {
        printf("Node %d -> Color %d\n", i, color[i]);
        if (color[i] > maxColor) {
            maxColor = color[i];
        }
    }

    printf("Minimum number of colors used: %d\n", maxColor);

    return 0;
}

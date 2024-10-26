#include <stdio.h>
#define n 6

void dfs(int graph[n][n], int curr, int vis[]) {
    printf("%d ", curr);
    vis[curr-1] = 1;

    for (int i=0; i<n; i++){
        if (graph[curr-1][i]==1 && vis[i]==0) {
            dfs(graph, i+1, vis);
        }
    }
}

int main() {
    int graph[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };
    int vis[n] = {0};
    
    printf("Depth First Search : \n");
    dfs(graph, 1, vis);
    return 0;
}

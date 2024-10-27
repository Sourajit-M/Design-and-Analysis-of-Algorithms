#include <stdio.h>
#define n 6

int stack[n];
int top = -1;

void push(int num) {
    if (top < n-1) {
        stack[++top] = num;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

void dfs(int graph[n][n], int start) {
    int vis[n] = {0};
    push(start);

    printf("Depth First Search: \n");
    
    while (top != -1) {
        int curr = pop();

        if (vis[curr-1] == 0) {
            printf("%d ", curr);
            vis[curr-1] = 1;
        }

        for (int i=n-1; i>=0; i--) {
            if (graph[curr-1][i]==1 && vis[i]==0) {
                push(i+1);
            }
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

    dfs(graph, 1);
    return 0;
}

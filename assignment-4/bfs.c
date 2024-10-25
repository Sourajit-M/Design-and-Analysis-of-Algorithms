#include<stdio.h>
#define n 6

int queue[100];
int front = 0, rear = 0;

void push(int num) {
    queue[rear] = num;
    rear++;
}

void pop() {
    front++;
}

void bfs(int graph[n][n], int vis[]) {
    push(1);
    vis[0] = 1; 
    while (front != rear) {
        int curr = queue[front];
        printf("%d ", curr);
        pop();
        
        for (int i = 0; i < n; i++) {
            if (graph[curr-1][i]==1 && vis[i]==0) {
                vis[i] = 1;
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
    
    int vis[n] = {0};
    bfs(graph, vis);
    return 0;
}

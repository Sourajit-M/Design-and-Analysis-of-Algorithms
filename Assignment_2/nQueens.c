#include <stdio.h>

#define N 5

void printSolution(int board[N][N]) {
    static int solutionCount = 1;
    printf("Solution %d:\n", solutionCount++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i] == 1)
            return 0;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j] == 1)
            return 0;
    return 1;
}

void solveNQUtil(int board[N][N], int col) {
    if (col >= N) {
        printSolution(board);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1);
            board[i][col] = 0;
        }
    }
}

void solveNQ() {
    int board[N][N] = {0};
    solveNQUtil(board, 0);
}

int main() {
    solveNQ();
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define N 5

int knightMoves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool isSafe(int x, int y, int board[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

bool knightTour(int x, int y, int movei, int board[N][N]) {
    if (movei == N * N) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int newX = x + knightMoves[i][0];
        int newY = y + knightMoves[i][1];
        
        if (isSafe(newX, newY, board)) {
            board[newX][newY] = movei;
            if (knightTour(newX, newY, movei + 1, board)) {
                return true;
            }
            board[newX][newY] = -1;
        }
    }
    
    return false;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool solveKnightTour() {
    int board[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    board[0][0] = 0;

    if (knightTour(0, 0, 1, board)) {
        printBoard(board);
        return true;
    }
    
    return false;
}

int main() {
    if (!solveKnightTour()) {
        printf("No solution exists!\n");
    }
    
    return 0;
}

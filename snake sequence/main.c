#include <stdio.h>
int rows;
int cols;
int max(int a, int b) {
    return a > b ? a : b;
}

int absolute(int a, int b) {
    return a > b ? a - b : b - a;
}

void snakeSequence(int mat[rows][cols], int rows, int cols) {
    int dp[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dp[i][j] = 1;
        }
    }

    int maxLen = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // down
            if (i > 0 && absolute(mat[i][j], mat[i-1][j]) == 1) {
                if (dp[i][j] < dp[i-1][j] + 1) {
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
            // right
            if (j > 0 && absolute(mat[i][j], mat[i][j-1]) == 1) {
                if (dp[i][j] < dp[i][j-1] + 1) {
                    dp[i][j] = dp[i][j-1] + 1;
                }
            }

            maxLen = max(dp[i][j], maxLen);
        }
    }

    printf("Maximum Length of snake Sequence is: %d\n", maxLen);
}

int main() {
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of cols: ");
    scanf("%d", &cols);

    int mat[rows][cols];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    snakeSequence(mat, rows, cols);

    return 0;
}

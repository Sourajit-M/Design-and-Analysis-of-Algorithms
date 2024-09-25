#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack_01(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {  
        for (int w = 0; w <= W; w++) {  
            if (wt[i-1] <= w) {  
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]] + val[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};     
    int W = 60;                  

    int n = sizeof(val) / sizeof(val[0]); 

    int max_value = knapsack_012(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", max_value);

    return 0;
}

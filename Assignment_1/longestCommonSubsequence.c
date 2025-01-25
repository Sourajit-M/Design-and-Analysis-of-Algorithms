#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void LCS(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);

    int dp[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    int length = dp[n][m];
    printf("Length of LCS: %d\n", length);

    char* lcs = (char*)malloc((length + 1) * sizeof(char));
    lcs[length] = '\0';

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (str1[i-1] == str2[j-1]) {
            lcs[--length] = str1[i-1];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LCS: %s\n", lcs);

    free(lcs);
}

int main() {
    char str1[] = "PQRSTPQRS”";
    char str2[] = "PRATPBRQRPS";
    


    LCS(str1, str2);

    return 0;
}

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lis(int nums[], int n){
    int dp[n+1];

    for(int i=0; i<n+1; i++){
        dp[i] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }

    int ans = -1;

    for(int i=0; i<n+1; i++){
        ans = max(dp[i], ans);
    }

    return ans;
}

int main(){
    int nums[] = {10,9,2,5,3,7,101,18};
    int n = sizeof(nums)/sizeof(nums[0]);

    int ans  = lis(nums, n);

    printf("Longest Increasing Subsequence is : %d", ans);
    return 0;
}
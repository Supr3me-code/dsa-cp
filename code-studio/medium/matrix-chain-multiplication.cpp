#include <bits/stdc++.h>

int helper(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = (arr[i - 1] * arr[k] * arr[j]) + helper(arr, i, k, dp) +
                   helper(arr, k + 1, j, dp);
        mini = min(mini, temp);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(101, vector<int>(101, -1));
    return helper(arr, 1, N - 1, dp);
    // Write your code here.
}
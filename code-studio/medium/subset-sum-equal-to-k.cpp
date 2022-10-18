#include <bits/stdc++.h>

bool helper(int n, int k, vector<int> &arr, int idx, vector<vector<int>> &dp) {
    if (k == 0) return true;
    if (idx == n || k < 0) return false;
    if (dp[idx][k] != -1) return dp[idx][k];
    int take = helper(n, k - arr[idx], arr, idx + 1, dp);
    int notTake = helper(n, k, arr, idx + 1, dp);
    return dp[idx][k] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(1001, vector<int>(1001, -1));
    return helper(n, k, arr, 0, dp);  // Write your code here.
}
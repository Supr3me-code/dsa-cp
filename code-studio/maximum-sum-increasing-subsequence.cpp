#include <bits/stdc++.h>

int helper(vector<int> &rack, int idx, int n, int prev, vector<int> &dp) {
    if (idx == n) {
        return 0;
    }
    if (dp[prev + 1] != -1) return dp[prev + 1];
    if (rack[idx] > rack[prev]) {
        return dp[prev + 1] = max(rack[idx] + helper(rack, idx + 1, n, idx, dp),
                                  helper(rack, idx + 1, n, prev, dp));
    } else {
        return dp[prev + 1] = helper(rack, idx + 1, n, prev, dp);
    }
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n) {
    vector<int> dp(n + 1, -1);
    return helper(rack, 0, n, -1, dp);
    // Write your code here
}
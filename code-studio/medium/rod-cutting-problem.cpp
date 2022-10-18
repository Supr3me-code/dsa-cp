int helper(vector<int> &price, int n, int idx, int prev, vector<int> &dp) {
    if (idx == n) return 0;
    if (dp[prev + 1] != -1) return dp[prev + 1];
    int cut = price[idx - prev - 1] + helper(price, n, idx + 1, idx, dp);
    int noTcut = helper(price, n, idx + 1, prev, dp);

    return dp[prev + 1] = max(cut, noTcut);
}

int cutRod(vector<int> &price, int n) {
    vector<int> dp(101, -1);
    return helper(price, n, 0, -1, dp);  // Write your code here.
}

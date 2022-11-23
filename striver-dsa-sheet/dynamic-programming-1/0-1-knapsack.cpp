// MEMOIZATION

int dp[1001][1001];
int helper(vector<int> &values, vector<int> &weights, int n, int w) {
    if (w == 0 || n == 0) return 0;
    if (dp[n][w] != -1) return dp[n][w];
    if (weights[n - 1] <= w) {
        return dp[n][w] = max(values[n - 1] + helper(values, weights, n - 1,
                                                     w - weights[n - 1]),
                              helper(values, weights, n - 1, w));
    } else {
        return dp[n][w] = helper(values, weights, n - 1, w);
    }
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            dp[i][j] = -1;
        }
    }
    return helper(values, weights, n, w);
}

// TABULAR

int findMaxForm(vector<string> &strs, int m, int n) {
    int i, j, k, l, p = strs.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (auto &s : strs) {
        int x = count(s.begin(), s.end(), '1');
        int y = s.size() - x;

        for (i = m; i >= y; i--) {
            for (j = n; j >= x; j--) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - y][j - x]);
            }
        }
    }
    return dp[m][n];
}
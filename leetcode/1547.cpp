class Solution {
   public:
    int dp[102][102];
    int recur(vector<int>& cuts, int start, int end) {
        if (start + 1 == end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start + 1; i < end; i++) {
            int cost = cuts[end] - cuts[start] + recur(cuts, start, i) +
                       recur(cuts, i, end);
            ans = min(ans, cost);
        }
        return dp[start][end] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int length = n;
        cuts.push_back(0);
        cuts.push_back(n);
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        return recur(cuts, 0, cuts.size() - 1);
    }
};
int dp[1001][1001];
int helper(string s, string t, int s_size, int t_size) {
    if (s_size == 0 || t_size == 0) {
        return 0;
    }
    if (dp[s_size][t_size] != -1) return dp[s_size][t_size];
    if (s[s_size - 1] == t[t_size - 1]) {
        return dp[s_size][t_size] = 1 + helper(s, t, s_size - 1, t_size - 1);
    } else {
        return dp[s_size][t_size] = max(helper(s, t, s_size - 1, t_size),
                                        helper(s, t, s_size, t_size - 1));
    }
}

int lcs(string s, string t) {
    memset(dp, -1, sizeof(dp));
    int s_size = s.size();
    int t_size = t.size();
    return helper(s, t, s_size, t_size);  // Write your code here
}
class Solution {
   public:
    int dp[301];
    int recur(int idx, string s, set<string>& word) {
        if (idx == s.size()) {
            return 1;
        }
        if (dp[idx] != -1) return dp[idx];
        string temp = "";
        for (int i = idx; i < s.size(); i++) {
            temp += s[i];
            if (word.find(temp) != word.end()) {
                if (recur(i + 1, s, word)) {
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        set<string> st;
        for (auto w : wordDict) {
            st.insert(w);
        }
        return recur(0, s, st);
    }
};
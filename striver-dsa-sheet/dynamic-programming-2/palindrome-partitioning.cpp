class Solution {
   public:
    int dp[501];
    bool isPalindrome(int i, int j, string str) {
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int recur(int idx, int size, string &str) {
        if (idx == size) return 0;
        int result = INT_MAX;
        if (dp[idx] != -1) return dp[idx];
        for (int j = idx; j < size; j++) {
            if (isPalindrome(idx, j, str)) {
                int x = 1 + recur(j + 1, size, str);
                result = min(result, x);
            }
        }
        return dp[idx] = result;
    }

    int palindromicPartition(string str) {
        memset(dp, -1, sizeof(dp));
        int n = str.size();
        return recur(0, n, str) - 1;
        // code here
    }
};

// TABULATION - REDUCED SPACE COMPLEXITY
class Solution {
   public:
    int dp[501];
    bool isPalindrome(int i, int j, string str) {
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int palindromicPartition(string str) {
        memset(dp, 0, sizeof(dp));
        int n = str.size();
        for (int i = n - 1; i >= 0; i--) {
            int result = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, str)) {
                    int x = 1 + dp[j + 1];
                    result = min(result, x);
                }
            }
            dp[i] = result;
        }
        return dp[0] - 1;
        // code here
    }
};
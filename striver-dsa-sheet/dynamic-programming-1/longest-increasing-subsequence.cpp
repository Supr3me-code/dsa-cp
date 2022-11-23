class Solution {
   public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums) + 1, -1);
        return solve(nums, 0, -1);
    }
    int solve(vector<int>& nums, int i, int prev_i) {
        if (i >= size(nums)) return 0;
        if (dp[prev_i + 1] != -1) return dp[prev_i + 1];
        int take = 0, dontTake = solve(nums, i + 1, prev_i);
        if (prev_i == -1 || nums[i] > nums[prev_i])
            take = 1 + solve(nums, i + 1, i);
        return dp[prev_i + 1] = max(take, dontTake);
    }
};

int longestIncreasingSubsequence(int arr[], int n) {
    // dp[i] represents i+1'th length LIS ending at minimum integer dp[i]
    int dp[n];
    // Base case
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        int maxval = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                maxval = max(maxval, dp[j]);
            }
        }
        dp[i] = maxval + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}

// binary search + dp
int longestIncreasingSubsequence(int arr[], int n) {
    int dp[n];  // dp[i] represents i+1'th length LIS ending at minimum integer
                // dp[i]
    int ans = 0;
    for (int i = 0; i < n; i++) {
        /*
            Since dp array stores elements in the sorted order therefore
            we can use binary search to find the correct position for
            arr[i] to be placed.
            And elements are present in the dp array from 0 to ans-1 position
            So we will be doing the binary search in this range.
        */
        int position = lower_bound(dp, dp + ans, arr[i]) - dp;
        dp[position] = arr[i];
        if (position == ans) {
            ans++;
        }
    }

    return ans;
}

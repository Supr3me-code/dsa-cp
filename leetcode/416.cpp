class Solution {
   public:
    int dp[201][10001];
    bool recur(int idx, vector<int>& nums, int target) {
        if (target == 0) {
            return true;
        }
        if (idx == nums.size() || target < 0) {
            return false;
        }
        if (dp[idx][target] != -1) return dp[idx][target];
        bool notTake = recur(idx + 1, nums, target);
        bool take = recur(idx + 1, nums, target - nums[idx]);

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            target += nums[i];
        }
        if (target & 1)
            return false;  // if target is odd... not possible for 2 subsets to
                           // have same sum
        target /= 2;       // we have to check if any subset has sum == target/2
        return recur(0, nums, target);
    }
};
// Given an integer array nums that may contain duplicates, return all possible
// subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in
// any order.

class Solution {
   public:
    void recur(vector<int> &nums, vector<vector<int>> &result,
               vector<int> &subset, int idx) {
        result.push_back(subset);
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            recur(nums, result, subset, i + 1);
            subset.pop_back();
        }
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        recur(nums, result, subset, 0);
        return result;
    }
};

void findSubsets(int ind, vector<int> &nums, vector<int> &ds,
                 vector<vector<int>> &ans) {
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++) {
        if (i != ind && nums[i] == nums[i - 1]) continue;
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
}

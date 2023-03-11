// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
// nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1, hi = nums.size() - 1, sum = 0 - nums[i];
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);

                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++;
                        hi--;
                    } else if (nums[lo] + nums[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return res;
    }
};

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    int i, j, k;
    for (i = 0; i < nums.size() - 2; i++) {
        for (j = i + 1; j < nums.size() - 1; j++) {
            for (k = j + 1; k < nums.size(); k++) {
                temp.clear();
                if (nums[i] + nums[j] + nums[k] == 0) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                }
                if (temp.size() != 0) ans.push_back(temp);
            }
        }
    }

    return ans;
}
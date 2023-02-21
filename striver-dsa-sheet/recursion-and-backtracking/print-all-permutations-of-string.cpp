// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.

class Solution {
   public:
    void recurCall(vector<int> &nums, vector<vector<int>> &answer, int idx) {
        if (idx == nums.size()) {
            answer.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            recurCall(nums, answer, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> answer;
        recurCall(nums, answer, 0);
        return answer;
    }
};

class Solution {
   private:
    void recurPermute(vector<int> &ds, vector<int> &nums,
                      vector<vector<int>> &ans, int freq[]) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

   public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++) freq[i] = 0;
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};
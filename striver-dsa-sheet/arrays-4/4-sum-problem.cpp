// Given an array nums of n integers, return an array of all the unique
// quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        if (nums.empty()) {
            return result;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int start = j + 1;
                int end = n - 1;
                int target_2 = target - nums[i] - nums[j];

                while (start < end) {
                    int two_sum = nums[start] + nums[end];
                    if (two_sum > target_2)
                        end--;

                    else if (two_sum < target_2)
                        start++;

                    else {
                        vector<int> aux(4, 0);
                        aux[0] = nums[i];
                        aux[1] = nums[j];
                        aux[2] = nums[start];
                        aux[3] = nums[end];
                        result.push_back(aux);

                        while (start < end && nums[start] == aux[2]) ++start;
                        while (start < end && nums[end] == aux[3]) --end;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return result;
    }
};

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    set<vector<int>> sv;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int x = (long long)target - (long long)nums[i] -
                        (long long)nums[j] - (long long)nums[k];

                if (binary_search(nums.begin() + k + 1, nums.end(), x)) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(x);
                    sort(v.begin(), v.end());
                    sv.insert(v);
                }
            }
        }
    }
    vector<vector<int>> res(sv.begin(), sv.end());
    return res;
}
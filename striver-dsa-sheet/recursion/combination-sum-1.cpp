// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen
// numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target
// is less than 150 combinations for the given input.

class Solution {
   public:
    void recursiveCall(int idx, vector<int> &candidates,
                       vector<vector<int>> &result, vector<int> &osf,
                       int target) {
        if (idx == candidates.size()) {
            if (target == 0) {
                result.push_back(osf);
            }
            return;
        }

        if (candidates[idx] <= target) {
            osf.push_back(candidates[idx]);
            recursiveCall(idx, candidates, result, osf,
                          target - candidates[idx]);
            osf.pop_back();
        }
        recursiveCall(idx + 1, candidates, result, osf, target);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> osf;
        recursiveCall(0, candidates, result, osf, target);
        return result;
    }
};
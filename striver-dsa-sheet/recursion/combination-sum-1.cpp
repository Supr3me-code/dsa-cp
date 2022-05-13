class Solution {
public:
    void recursiveCall(int idx, vector<int> &candidates, vector<vector<int>> &result,vector<int> &osf, int target){
        if(idx==candidates.size()){
            if(target==0){
                result.push_back(osf);
            }
            return;
        }
        
        if(candidates[idx]<=target){
            osf.push_back(candidates[idx]);
            recursiveCall(idx, candidates, result, osf, target-candidates[idx]);
            osf.pop_back();
        }
        recursiveCall(idx+1, candidates, result, osf, target);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> osf;
        recursiveCall(0,candidates, result, osf, target);
        return result;
    }
};
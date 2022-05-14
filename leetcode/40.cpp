class Solution {
public:
    void recursiveCall(int idx, vector<int> &candidates, vector<vector<int>> &result,vector<int> &osf, int target){
        if(target==0){
            result.push_back(osf);
            return;
        }
    
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            osf.push_back(candidates[i]);
            recursiveCall(i+1, candidates, result, osf, target-candidates[i]);
            osf.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> osf;
        sort(candidates.begin(), candidates.end());
        recursiveCall(0,candidates, result, osf, target);
        return result;
    }
};
class Solution {
public:
    void recurCall(vector<int> &nums, vector<vector<int>> &answer, int idx){
        if(idx == nums.size()){
            answer.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            recurCall(nums, answer, idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        recurCall(nums, answer, 0);
        return answer;
    }
};
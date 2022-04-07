class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = floor(n/3);
        vector<int> result;
        
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            um[nums[i]]++;
        }
        
        for(auto i:um){
            if(i.second > majority){
                result.push_back(i.first);
            }
        }
        
        return result;
        
    }
};
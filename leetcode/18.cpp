class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        
        if(nums.empty()){
            return result;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int start = j+1;
                int end = n-1;
                int target_2 = target - nums[i] - nums[j];
                
                while(start<end){
                    int two_sum = nums[start]+nums[end];
                    if(two_sum > target_2) end--;

                    else if(two_sum < target_2) start++;

                    else{
                        vector<int> aux(4,0);
                        aux[0] = nums[i];
                        aux[1] = nums[j];
                        aux[2] = nums[start];
                        aux[3] = nums[end];
                        result.push_back(aux);
                    
                        while(start<end && nums[start]==aux[2]) ++start;
                        while(start<end && nums[end]==aux[3]) --end;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) ++j;
            }
            while(i+1<n && nums[i+1]==nums[i]) ++i;
        }
        return result;
    }
};
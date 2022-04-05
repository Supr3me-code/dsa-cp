class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int sum = (n * (n+1))/2;
        
        int calculated_sum = 0;
        for(int i=0;i<n; i++){
            calculated_sum += nums[i];
        }
        
        if(sum == calculated_sum){
            return 0;
        }
        
        return sum - calculated_sum;
    }
};
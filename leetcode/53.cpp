// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxSum = INT_MIN;
//         int len = nums.size();
        
//         for(int i=0;i<len;i++){
//             int sum = 0;
//             for(int j=i;j<len;j++){
//                 sum += nums[j];
//                 maxSum = max(maxSum, sum);
//             }
//         }
        
//         return maxSum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        
        for(auto i:nums){
            sum += i;
            maxSum = max(maxSum, sum);
            if(sum<0)
                sum = 0;
        }
        
        return maxSum;
    }
};
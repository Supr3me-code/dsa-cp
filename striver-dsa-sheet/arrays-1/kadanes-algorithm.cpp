// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

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
// Given a binary array nums, return the maximum number of consecutive 1's in the array.



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, local=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==1){
                local++;
            }else{
                res = max(res, local);
                local = 0;
            }
        }
        res = max(res, local);
        return res;
    }
};
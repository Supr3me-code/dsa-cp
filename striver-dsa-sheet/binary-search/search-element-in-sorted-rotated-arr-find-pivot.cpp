/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            
            //check if left half is sorted
            if(nums[low]<=nums[mid]){
                //check if target is present in the left half
                if(target>=nums[low] && target<=nums[mid]){
                    high = mid-1;
                }
                //else it is in the right half
                else{
                    low = mid+1;
                }
            }
            //else right half is sorted
            else{
                //check if target is in the right half
                if(target>=nums[mid] && target<=nums[high]){
                    low = mid+1;
                }
                //else it is in the left half
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
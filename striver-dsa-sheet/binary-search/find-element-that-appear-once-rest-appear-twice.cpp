/*
ou are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

//We can solve this question in O(n) TC ans O(1) SC by XORing all the elements, since xor of same numbers is 0 and 0^n = n therefore only the number
// that doesnt have a pair will be left

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size()-2;
        
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == nums[mid^1])
                left = mid+1;
            else
                right = mid-1;
        }
        return nums[left];
    }
};
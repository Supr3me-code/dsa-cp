/*
ou are given a sorted array consisting of only integers where every element
appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

// We can solve this question in O(n) TC ans O(1) SC by XORing all the elements,
// since xor of same numbers is 0 and 0^n = n therefore only the number
//  that doesnt have a pair will be left

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right =
            nums.size() -
            2;  // marked the second last element as the right and not the last
                // element as if the answer is at the last index
        // we want left and right to cross each other but in this case left will
        // never be able to cross right as right will keep pointing at the last
        // element and there's nothing to the right of it to cross over to

        // observation:
        //  1. to the left of the answer each 1st number of a pair has an even
        //  index -> 2nd number has odd index
        //  2. to the right of the answer each 1st number of a pair has an odd
        //  index -> --"--          even index

        while (left <= right) {
            int mid = (left + right) / 2;
            // if mid==odd then mid^1=="even number just before it"
            // if mid==even then mid^1=="odd number just after it"
            // so if the numbers at these 2 indices are equal then according to
            // the observation,
            // they belong to the left of the answer so we should check to the
            // right of nums[mid] , therefore left = mid+1
            if (nums[mid] == nums[mid ^ 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return nums[left];
    }
};

class Solution {
   public:
    int findSingleElement(vector<int>& nums) {
        int n = nums.size();
        int elem = 0;
        for (int i = 0; i < n; i++) {
            elem = elem ^ nums[i];
        }

        return elem;
    }
};
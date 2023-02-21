/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For
example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
[4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;

            // check if left half is sorted
            if (nums[low] <= nums[mid]) {
                // check if target is present in the left half
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                }
                // else it is in the right half
                else {
                    low = mid + 1;
                }
            }
            // else right half is sorted
            else {
                // check if target is in the right half
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }
                // else it is in the left half
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;  //<---step 1

    while (low <= high) {                     //<--- step 2
        int mid = (low + high) >> 1;          //<----step 3
        if (nums[mid] == target) return mid;  // <---step 4

        if (nums[low] <= nums[mid]) {  //<---step 5
            if (nums[low] <= target && nums[mid] >= target)
                high = mid - 1;  //<---step 6
            else
                low = mid + 1;  //<---step 7
        } else {                //<---step 7
            if (nums[mid] <= target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;  //<---step 8
}

float median(int nums1[], int nums2[], int m, int n) {
    int finalArray[n + m];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            finalArray[k++] = nums1[i++];
        } else {
            finalArray[k++] = nums2[j++];
        }
    }
    if (i < m) {
        while (i < m) finalArray[k++] = nums1[i++];
    }
    if (j < n) {
        while (j < n) finalArray[k++] = nums2[j++];
    }
    n = n + m;
    if (n % 2 == 1)
        return finalArray[((n + 1) / 2) - 1];
    else
        return ((float)finalArray[(n / 2) - 1] + (float)finalArray[(n / 2)]) /
               2;
}

float median(int num 1 [], int num2[], int m, int n) {
    if (m > n)
        return median(
            nums2, nums1, n,
            m);  // ensuring that binary search happens on minimum size array

    int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
    while (low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = medianPos - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if ((m + n) % 2 != 0)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        } else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}

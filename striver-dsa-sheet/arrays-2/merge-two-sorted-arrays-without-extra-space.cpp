// You are given two integer arrays nums1 and nums2, sorted in non-decreasing
// order, and two integers m and n, representing the number of elements in nums1
// and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be
// stored inside the array nums1. To accommodate this, nums1 has a length of m +
// n, where the first m elements denote the elements that should be merged, and
// the last n elements are set to 0 and should be ignored. nums2 has a length of
// n.

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < n + m; i++) {
            nums1[i] = nums2[i - m];
        }

        sort(nums1.begin(), nums1.end());
    }
};

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m,
                                 int n) {
    int i = m - 1;
    int j = n - 1;
    int lastIndex = m + n - 1;

    while (j >= 0) {
        if (i >= 0 && arr1[i] > arr2[j]) {
            arr1[lastIndex] = arr1[i];
            i--;
        } else {
            arr1[lastIndex] = arr2[j];
            j--;
        }

        lastIndex--;
    }
    return arr1;
}

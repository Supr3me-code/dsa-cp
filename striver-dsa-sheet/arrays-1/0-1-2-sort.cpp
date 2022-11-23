// Given an array nums with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors in
// the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and
// blue, respectively.

// You must solve this problem without using the library's sort function.

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(3);

        for (auto i : nums) {
            count[i]++;
        }
        int idx = 0;
        for (int i = 0; i < count[0]; i++) {
            nums[idx++] = 0;
        }
        for (int i = 0; i < count[1]; i++) {
            nums[idx++] = 1;
        }
        for (int i = 0; i < count[2]; i++) {
            nums[idx++] = 2;
        }

        return;
    }
};

void sort012(int* arr, int n) {
    int i = 0;
    int nextZero = 0;
    int nextTwo = n - 1;

    while (i <= nextTwo) {
        if (arr[i] == 0) {
            swap(arr[i], arr[nextZero]);
            i++;
            nextZero++;
        } else if (arr[i] == 2) {
            swap(arr[i], arr[nextTwo]);
            nextTwo--;
        } else {
            i++;
        }
    }
}
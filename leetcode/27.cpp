class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                result++;
                nums[i] = -1;
            }
        }
        result = nums.size() - result;
        cout << endl;
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != -1) {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            } else {
                fast++;
            }
        }
        return result;
    }
};
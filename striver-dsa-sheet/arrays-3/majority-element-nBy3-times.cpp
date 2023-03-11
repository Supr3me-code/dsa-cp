// Given an integer array of size n, find all elements that appear more than ⌊
// n/3 ⌋ times.

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = floor(n / 3);
        vector<int> result;

        unordered_map<int, int> um;
        for (int i = 0; i < n; i++) {
            um[nums[i]]++;
        }

        for (auto i : um) {
            if (i.second > majority) {
                result.push_back(i.first);
            }
        }

        return result;
    }
};

vector<int> majorityElement(int nums[], int n) {
    int sz = n;
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
    for (i = 0; i < sz; i++) {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
        else if (count1 == 0) {
            num1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            num2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = count2 = 0;
    for (i = 0; i < sz; i++) {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
    }
    if (count1 > sz / 3) ans.push_back(num1);
    if (count2 > sz / 3) ans.push_back(num2);
    return ans;
}
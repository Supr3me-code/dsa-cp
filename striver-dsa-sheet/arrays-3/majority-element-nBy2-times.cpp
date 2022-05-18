// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        int max = INT_MIN;
        int result;
        for(auto x:um){
            if(x.second>max){
                max = x.second;
                result = x.first;
            }
        }
        return result;
    }
};
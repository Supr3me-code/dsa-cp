class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        for(auto n:nums){
            um[n]++;
        }
        for(auto i:um){
            if(i.second==1)
                return i.first;
        }
        return -1;
    }
};
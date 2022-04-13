class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()){
            return 0;
        }
        
        set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        
        int result = 0;
        
        for(int x:nums){
            if(!s.count(x-1)){
                int currentNumber = x;
                int currentLength = 1;
                while(s.count(currentNumber+1)){
                    currentLength++;
                    currentNumber++;
                }
                
                result = max(result, currentLength);
            }
        }
        return result;
    }
};
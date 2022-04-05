class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(3);
        
        for(auto i:nums){
            count[i]++;
        }
        
        int idx = 0;
        for(int i=0;i<count[0];i++){
            nums[idx++] = 0;
        }
        for(int i=0;i<count[1];i++){
            nums[idx++] = 1;
        }
        for(int i=0;i<count[2];i++){
            nums[idx++] = 2;
        }
        
        return;
    }
};
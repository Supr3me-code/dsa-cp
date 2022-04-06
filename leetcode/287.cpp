// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         set<int> s;
//         for(auto i:nums){
//             if(s.find(i)==s.end()){
//                 s.insert(i);
//             }else{
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        fast = nums[0];
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
};
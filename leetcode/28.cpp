class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle == "") return 0;
        
        int haylen = haystack.size();
        int needlen = needle.size();
        
        for(int i=0;i<haylen-needlen+1;i++){
            if(needle == haystack.substr(i,needlen)){
                return i;
            }
        }
        
        return -1;
    }
};
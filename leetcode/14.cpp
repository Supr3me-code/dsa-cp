class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int shortestLength = INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<shortestLength){
                shortestLength = strs[i].size();
            }
        }
        
        for(int i=0;i<shortestLength;i++){
            char c = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] != c){
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};

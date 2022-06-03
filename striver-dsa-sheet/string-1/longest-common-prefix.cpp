class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        int min_length_string = INT_MAX;
        for(int i=0;i<strs.size();i++){
            int local_length = strs[i].length();
            if(local_length<min_length_string){
                min_length_string = local_length;
            }
        }
        
        for(int i=0;i<min_length_string;i++){
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]==strs[j+1][i]){
                    continue;
                }else{
                    return "";
                }
            }
            common+=strs[0][i];
        }
        return common;
    }
};
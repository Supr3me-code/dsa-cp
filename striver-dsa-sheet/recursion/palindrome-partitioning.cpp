// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.



class Solution {
public:
    
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    void findAllPalindromes(string s, vector<vector<string>> &result, vector<string> &path, int idx){
        if(idx == s.size()){
            result.push_back(path);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx, i-idx+1));
                findAllPalindromes(s,result,path,i+1);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        findAllPalindromes(s, result, path, 0);
        return result;
    }
};
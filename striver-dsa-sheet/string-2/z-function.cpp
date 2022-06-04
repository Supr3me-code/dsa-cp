/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

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
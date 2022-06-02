/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); //reverse the entire string
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' '; // for every word after the 1st word, brgin it with a space
                int j = i;
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; } // store the word
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex); // reverse the word
                i = j; // set pointers to the next word
            }
        }
        s.erase(s.begin() + storeIndex, s.end()); // erase all extra stuff after all words are traversed
        return s;
    }
};
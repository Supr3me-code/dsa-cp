/*
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
*/

class Solution {
public:
    int compareVersion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int i = 0, j = 0; // variables(pointers) used for moving
        int number1 = 0, number2 = 0;  // numbers that generated between any two dots of the strings
        // start traversing from string 1 and string 2
        while(i < n1 || j < n2){
            // generating number between dots for string s1
            while(i < n1 && s1[i] != '.'){
                number1 = number1 * 10 + (s1[i] - '0');
                i++;
            }
            // generating number between dots for string s2
            while(j < n2 && s2[j] != '.'){
                number2 = number2 * 10 + (s2[j] - '0');
                j++;
            }
            // if number1 is greater than number2, from here return 1
            if(number1 > number2) return 1;
             // if number1 is less than number2, from here return -1
            if(number1 < number2) return -1;
            // if equal then we have to proceed further
            // again give numbers to zero, as we again generate numbers b/w dots 
            number1 = 0, number2 = 0;
            // move both pointers
            i++;
            j++;
        }
        // after traversing whole string, if all the versions are equal, that means
        // strings are equal, so return 0
        return 0;
    }
};
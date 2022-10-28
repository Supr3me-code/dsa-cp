// FIRST ATTEMPT------------------------

// class Solution {
//    public:
//     bool isAnagram(string a, string b) {
//         if (a.size() != b.size()) return false;
//         int count[256] = {0};
//         for (int i = 0; a[i] && b[i]; i++) {
//             count[a[i]]++;
//             count[b[i]]--;
//         }
//         for (int i = 0; i < 256; i++) {
//             if (count[i]) return false;
//         }
//         return true;
//     }

//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> result;

//         int n = strs.size();
//         for (int i = 0; i < n - 1; i++) {
//             vector<string> temp;
//             if (strs[i] != "dishant") {
//                 temp.push_back(strs[i]);
//                 for (int j = i + 1; j < n; j++) {
//                     if (isAnagram(strs[i], strs[j])) {
//                         temp.push_back(strs[j]);
//                         strs[j] = "dishant";
//                     }
//                 }
//                 strs[i] = "dishant";
//                 result.push_back(temp);
//             }
//         }

//         if (strs[n - 1] != "dishant") {
//             vector<string> temp;
//             temp.push_back(strs[n - 1]);
//             result.push_back(temp);
//         }
//         return result;
//     }
// };

// OPTIMIZED------------------

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s;
            sort(t.begin(),
                 t.end());  // calculating the sorted version of this string
            mp[t].push_back(s);  // storing it in its sorted array group
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

// OPTIMIZED WAY OF SORTING WHEN ALL CHAR ARE EITHER SMALL/BIG-----------------

// string strSort(string s) {
//     int counter[26] = {0};
//     for (char c : s) {
//         counter[c - 'a']++;
//     }
//     string t;
//     for (int c = 0; c < 26; c++) {
//         t += string(counter[c], c + 'a');
//     }
//     return t;
// }

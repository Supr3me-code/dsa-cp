// Given a string s, find the length of the longest substring without repeating
// characters.

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        int left = 0;
        int right = 0;
        int length = 0;
        int n = s.size();

        while (right < n) {
            if (mp[s[right]] != -1) {
                left = max(mp[s[right]] + 1, left);
            }

            mp[s[right]] = right;
            length = max(length, right - left + 1);
            right++;
        }

        return length;
    }
};

int solve(string str) {
    if (str.size() == 0) return 0;
    int maxans = INT_MIN;
    for (int i = 0; i < str.length();
         i++)  // outer loop for traversing the string
    {
        unordered_set<int> set;
        for (int j = i; j < str.length();
             j++)  // nested loop for getting different string starting with
                   // str[i]
        {
            if (set.find(str[j]) !=
                set.end())  // if element if found so mark it as ans and break
                            // from the loop
            {
                maxans = max(maxans, j - i);
                break;
            }
            set.insert(str[j]);
        }
    }
    return maxans;
}

int solve(string str) {
    if (str.size() == 0) return 0;
    int maxans = INT_MIN;
    unordered_set<int> set;
    int l = 0;
    for (int r = 0; r < str.length();
         r++)  // outer loop for traversing the string
    {
        if (set.find(str[r]) != set.end())  // if duplicate element is found
        {
            while (l < r && set.find(str[r]) != set.end()) {
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        maxans = max(maxans, r - l + 1);
    }
    return maxans;
}
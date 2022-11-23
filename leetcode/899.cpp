class Solution {
   public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            int n = s.size();
            string ss = s + s;
            for (int i = 1; i < n; i++) {
                string subString = ss.substr(i, n);
                s = min(s, subString);
            }
            return s;
        }
        sort(s.begin(), s.end());
        return s;
    }
};

// if k>1 smallest string will always be the sorted one
// for k==1 we will chwck each one
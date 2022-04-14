class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        unordered_map<int, int> mp;
       mp[0] = -1;
       int mx = 0, sum = 0;
       for(int i=0; i<n;i++)
       {
           sum += A[i];
           if(mp.find(sum) != mp.end())
           mx = max(mx, i-mp[sum]);
           else
           mp[sum] = i;
       }
       return mx;
        
    }
};

// whenever the cumulative sum occurs twice that means the numbers in between have a sum 0.

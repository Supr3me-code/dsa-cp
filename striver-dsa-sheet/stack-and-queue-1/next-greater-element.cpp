class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            st.push(nums[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }

            if (st.empty()) {
                ans.push_back(-1);
            } else {
                ans.push_back(st.top());
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//---- for non circular array

#include <bits/stdc++.h>
vector<int> nextGreater(vector<int>& arr, int n) {
    vector<int> ans;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        int element = arr[i];
        if (!st.empty() && st.top() > element) {
            ans.push_back(st.top());
        } else if (!st.empty() && st.top() <= element) {
            while (!st.empty() && st.top() <= element) {
                st.pop();
            }
            if (st.empty()) {
                ans.push_back(-1);
            } else {
                ans.push_back(st.top());
            }
        } else {
            ans.push_back(-1);
        }
        st.push(element);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
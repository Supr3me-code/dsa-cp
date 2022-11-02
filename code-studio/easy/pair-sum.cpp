#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s) {
    unordered_map<int, int> myMap;
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++) {
        int curr = s - arr[i];
        if (myMap.find(curr) != myMap.end()) {
            for (int j = 0; j < myMap[curr]; j++) {
                vector<int> a;
                a.push_back(min(curr, arr[i]));
                a.push_back(max(curr, arr[i]));
                ans.push_back(a);
            }
        }
        if (myMap.find(arr[i]) != myMap.end())
            myMap[arr[i]]++;
        else
            myMap[arr[i]] = 1;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
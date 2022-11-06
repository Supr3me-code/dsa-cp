#include <bits/stdc++.h>
int firstMissing(int arr[], int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    int x = 1;
    while (true) {
        if (mp.find(x) == mp.end()) {
            return x;
        }
        x++;
    }
    // Write your code here.
}
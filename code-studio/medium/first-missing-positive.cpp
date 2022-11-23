#include <bits/stdc++.h>
int firstMissing(int arr[], int n) {
    // Write your code here.
    const int lim = 1e5;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= lim) {
            int idx = arr[i];
            while (idx - 1 >= 0 && idx - 1 < n && arr[idx - 1] <= lim) {
                swap(arr[i], arr[idx - 1]);
                arr[idx - 1] += lim;
                idx = arr[i];
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] - lim != ans) return ans;
        ans++;
    }
    return ans;
}
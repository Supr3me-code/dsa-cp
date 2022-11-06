#include <bits/stdc++.h>
using namespace std;

bool helper(int n, int m, int k, int arr[]) {
    if (m < k) return false;
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    for (int i = 0; i < k; i++) {
        if (s.find(i) == s.end()) return false;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != k) count++;
    }
    if (count < m) return false;

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (helper(n, m, k, arr))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // your code goes here
    return 0;
}

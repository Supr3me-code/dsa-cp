#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int firstMax = 0;
        int secondMax = 0;
        for (auto x : mp) {
            if (x.second >= firstMax) {
                secondMax = firstMax;
                firstMax = x.second;
            } else if (x.second > secondMax) {
                secondMax = x.second;
            }
        }
        int ans = max(secondMax, (firstMax + 1) / 2);
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        int mn = n;
        for (auto &i : m) {
            int val = 0;
            if (i.first & 1)
                val = i.first - 1;
            else
                val = i.first + 1;
            int ans = i.second;
            auto it = m.find(val);
            if (it != m.end()) ans += m[val];
            if (n - ans < mn) mn = n - ans;
        }
        cout << mn << endl;
    }

    return 0;
}
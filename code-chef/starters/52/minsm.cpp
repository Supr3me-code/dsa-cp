#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll res = arr[0];
        for (ll i = 0; i < n; i++) {
            res = __gcd(res, arr[i]);
        }
        cout << res * n << endl;
    }
    return 0;
}

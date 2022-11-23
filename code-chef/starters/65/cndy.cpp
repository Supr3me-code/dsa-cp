#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool helper(ll arr[], ll n) {
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < 2 * n; i++) {
        mp[arr[i]]++;
        if (mp[arr[i]] > 2) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[2 * n];
        for (ll i = 0; i < 2 * n; i++) {
            cin >> arr[i];
        }

        if (helper(arr, n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // your code goes here
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool helper(ll arr[], ll n, ll k) {
    if (n == 1) {
        if (arr[0] == k)
            return true;
        else
            return false;
    }
    for (ll i = 0; i < n - 1; i++) {
        if (arr[i] == k) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (helper(arr, n, k))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // your code goes here
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxAngry(ll n, ll k) {
    ll angry = (n * (n - 1)) / 2;
    if (k < n / 2) {
        ll temp = n - 2 * k;
        angry -= (temp * (temp - 1)) / 2;
    }

    return angry;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        cout << maxAngry(n, k) << endl;
    }
    // your code goes here
    return 0;
}

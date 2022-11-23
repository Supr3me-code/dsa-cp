#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPrime(ll n) {
    // Corner case
    if (n <= 1) return false;

    // Check from 2 to square root of n
    ll v = sqrt(n);
    for (ll i = 2; i <= v; i++)
        if (n % i == 0) return false;

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll sum = a + b;
        bool x = isPrime(sum);
        if (x)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    // your code goes here
    return 0;
}
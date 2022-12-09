#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll counter = 0;
        while (n > 1) {
            n /= 2;
            counter++;
        }

        ll sum = a * counter + b * (counter - 1);
        cout << sum << endl;
    }
    // your code goes here
    return 0;
}

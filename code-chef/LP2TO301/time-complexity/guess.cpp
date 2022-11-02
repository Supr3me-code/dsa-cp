#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        // int total = n*m;
        // int expected = (n/2)*((m+1)/2) + ((n+1)/2)*(m/2);
        // int gcd = __gcd(expected,total);
        // cout<<expected/gcd<<"/"<<total/gcd<<endl;

        ll evenInN = n / 2;
        ll oddInN = (n + 1) / 2;
        ll evenInM = m / 2;
        ll oddInM = (m + 1) / 2;
        ll totalComb = n * m;
        ll case1 = evenInM * oddInN;
        ll case2 = oddInM * evenInN;
        ll totalPossibilities = case1 + case2;
        ll GCD = __gcd(totalPossibilities, totalComb);
        totalPossibilities /= GCD;
        totalComb /= GCD;
        cout << totalPossibilities << "/" << totalComb << endl;
    }
    // your code goes here
    return 0;
}

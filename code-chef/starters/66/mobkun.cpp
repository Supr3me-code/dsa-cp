#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool helper(int n, int m, int k, int x) {
    // if(k==1) return true;
    int total = n * (k - 1) + (n + m);
    int relative = x % total;
    if (relative == 0) return true;
    if (relative > n * (k - 1))
        return true;
    else
        return false;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        cin >> n >> m >> k >> x;
        if (helper(n, m, k, x))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // your code goes here
    return 0;
}

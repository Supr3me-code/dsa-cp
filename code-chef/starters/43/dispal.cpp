#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (x > ceil((double)n / 2)) {
            cout << -1 << endl;
            return;
        }
        if (n == 1) {
            cout << 'a' << endl;
            return;
        }
        string s = "";
        char c = 'a';
        if (n % 2 == 1 && x == ceil((double)n / 2)) {
            for (int i = 0; i < x - 1; i++) {
                s += (c + i);
            }
            string s1 = s;
            reverse(s1.begin(), s1.end());
            s += c + x - 1;
            s += s1;
            cout << s << endl;
            return;
        }
        for (int i = 0; i < x; i++) {
            s += (c + i);
        }
        for (int i = x; i < n / 2; i++) {
            s += 'a';
        }
        string s1 = s;
        reverse(s1.begin(), s1.end());
        if (n % 2) s += 'a';
        s += s1;
        cout << s << endl;
    }
    return 0;
}
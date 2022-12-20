#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int u, v, a, s;
        cin >> u >> v >> a >> s;
        int x = pow(u, 2) - (2 * a * s);
        x = sqrt(x);
        if (x <= v)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // your code goes here
    return 0;
}

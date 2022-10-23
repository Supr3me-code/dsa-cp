#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1)
            cout << 3;
        else if (n == 2)
            cout << 21;
        else if (n == 3)
            cout << 111;
        else {
            cout << 2;
            for (int i = 1; i <= n - 2; i++) cout << 0;
            cout << 1;
        }
        cout << "\n";
    }
    return 0;
}
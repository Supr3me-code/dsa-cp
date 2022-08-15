#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // x-2b, 2+b
        bool done = false;
        for (int i = 1; i < sqrt(x); i++) {
            if ((x - 2 * i) % (2 + i) == 0 && x != 2 * i) {
                done = true;
                break;
            }
        }
        if (done) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
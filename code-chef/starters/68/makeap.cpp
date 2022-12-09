#include <bits/stdc++.h>
using namespace std;

bool helper(int n, int a[]) {}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, c;
        cin >> a >> c;

        if ((c - a) % 2 != 0)
            cout << -1 << endl;
        else {
            int x = (c - a) / 2;
            cout << a + x << endl;
        }
    }
    return 0;
}
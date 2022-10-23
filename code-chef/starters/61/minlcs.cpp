#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        map<char, int> x;
        map<char, int> y;
        int counter = 0;

        for (int i = 0; i < n; i++) {
            x[a[i]]++;
            y[b[i]]++;
        }

        for (int i = 0; i < n; i++) {
            int temp = 0;
            int v = 0;
            if (x.find(a[i]) != x.end()) temp = x[a[i]];
            if (y.find(a[i]) != y.end()) v = y[a[i]];
            int kk = min(temp, v);
            counter = max(counter, kk);
        }
        cout << counter << endl;
    }
    // your code goes here
    return 0;
}

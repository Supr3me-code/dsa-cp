#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int counter = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) counter++;
        }
        cout << counter << endl;
    }
    // your code goes here
    return 0;
}

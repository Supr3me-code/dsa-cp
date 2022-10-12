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
        vector<int> v;
        for (int i = 0; i < s.size(); i++) {
            v.push_back(s[i] - '0');
        }
        int one = 0, zero = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1)
                one++;
            else
                zero++;
        }
        if (v.size() % 2 == 0) {
            if (one % 2 && zero % 2)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    // your code goes here
    return 0;
}

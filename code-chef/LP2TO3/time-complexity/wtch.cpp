#include <iostream>
using namespace std;

int maxNumberOfWatchers(string s, int n) {
    int result = 0;
    if (n == 1) {
        if (s[0] == '1')
            return 0;
        else
            return 1;
    }
    if (s[0] == '0' && s[1] == '0') {
        s[0] = '1';
        result++;
    }
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '1')
            i++;
        else if (s[i - 1] == '0' && s[i + 1] == '0') {
            s[i] = '1';
            result++;
        }
    }
    if (s[n - 1] == '0' && s[n - 2] == '0') {
        result++;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        cout << maxNumberOfWatchers(s, n) << endl;
    }
    // your code goes here
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A')
                s[i] = 'T';
            else if (s[i] == 'T')
                s[i] = 'A';
            else if (s[i] == 'C')
                s[i] = 'G';
            else
                s[i] = 'C';
        }
        cout << s << endl;
    }
    return 0;
}
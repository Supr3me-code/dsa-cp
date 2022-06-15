#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string seq;
        cin >> seq;

        string res = "";
        for (int i = 1; i <= n - 1; i += 2) {
            if (seq.substr(i - 1, 2) == "00")
                res += 'A';
            else if (seq.substr(i - 1, 2) == "01")
                res += 'T';
            else if (seq.substr(i - 1, 2) == "10")
                res += 'C';
            else
                res += 'G';
        }
        cout << res << endl;
    }
    return 0;
}

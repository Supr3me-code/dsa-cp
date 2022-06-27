#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;
        int result = 0;
        while (p >= 100) {
            p -= 100;
            result++;
        }
        int left = 10 - result;
        if (p > left) {
            cout << -1 << endl;
        } else {
            result += p;
            cout << result << endl;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    // smallest reachable number is 2L
    // highest reachable will be 2R;,main
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << (2 * r) - (2 * l) + 1 << endl;
    }
    // your code goes here
    return 0;
}

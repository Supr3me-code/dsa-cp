#include <iostream>
using namespace std;

bool isPowerOf2(int x) { return x && (!(x & (x - 1))); }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int larger = (a > b) ? a : b;
        int smaller;
        if (larger == a) {
            smaller = b;
        } else {
            smaller = a;
        }
        if (larger % smaller == 0) {
            int q = larger / smaller;
            if (isPowerOf2(q)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
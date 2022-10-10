#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int i = n * x;
        if (i % 4 == 0)
            cout << i / 4 << endl;
        else
            cout << (i / 4) + 1 << endl;
    }
    return 0;
}
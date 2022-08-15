#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int final;

        if (x <= 100) {
            final = x;
        } else if (x <= 1000) {
            final = x - 25;
        } else if (x <= 5000) {
            final = x - 100;
        } else {
            final = x - 500;
        }
        cout << final << endl;
    }
    return 0;
}
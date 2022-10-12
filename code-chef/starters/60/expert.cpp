#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x % 2 == 0) {
            if (y >= x / 2)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            if (y > x / 2)
                cout << "yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    // your code goes here
    return 0;
}

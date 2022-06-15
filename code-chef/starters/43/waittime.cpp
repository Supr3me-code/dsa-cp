#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, m;
        cin >> k >> m;
        int totalDays = k * 7;
        int remaining = totalDays - m;
        cout << remaining << endl;
    }
    return 0;
}

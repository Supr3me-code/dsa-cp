#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n <= m) {
            int p = 1, cd = n + 1, x = 1;
            for (int i = 1; i <= n; i++) {
                cout << p << " ";
                for (int j = 1; j < m; j++) {
                    cout << p + (i * x) << " ";
                    x++;
                }
                x = 1;
                p = p + cd;
            }
        } else {
            int p = 1, cd = m + 1, x = 1;
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
                for (int j = 1; j < m; j++) {
                    cout << i + cd * x << " ";
                    x++;
                }
                x = 1;
                cd++;
                cout << endl;
            }
        }
    }
    return 0;
}
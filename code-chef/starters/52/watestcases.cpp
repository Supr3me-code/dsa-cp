#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        string bin;
        cin >> bin;

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (bin[i] == '0' && arr[i] < res) {
                res = arr[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}

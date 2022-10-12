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

        int count[11];
        for (int i = 0; i < 11; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }
        int maxi = 0;
        for (int i = 0; i < 11; i++) {
            maxi = max(maxi, count[i]);
        }
        cout << n - maxi << endl;
    }
    // your code goes here
    return 0;
}

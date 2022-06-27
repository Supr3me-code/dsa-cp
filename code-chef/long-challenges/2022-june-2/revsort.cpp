#include <bits/stdc++.h>
using namespace std;

int revSort() {
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] + arr[i + 1] > x) {
                return 0;
            } else {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (revSort()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
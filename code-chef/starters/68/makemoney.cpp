#include <bits/stdc++.h>
using namespace std;

bool helper(int n, int a[]) {}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, c;
        cin >> n >> x >> c;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int totalMoney = 0;
        for (int i = 0; i < n; i++) {
            if (c < x - arr[i])
                totalMoney += x - c;
            else
                totalMoney += arr[i];
        }

        cout << totalMoney << endl;
    }
    return 0;
}
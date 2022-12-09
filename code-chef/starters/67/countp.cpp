#include <bits/stdc++.h>
using namespace std;

bool helper(int n, int a[]) {
    int numberOfOdd = 0;
    int numberOfEven = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            numberOfOdd++;
        } else
            numberOfEven++;
    }
    if (numberOfOdd % 2 || numberOfEven == n) {
        return false;
    } else
        return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (helper(n, a))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
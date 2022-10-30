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
        int counter = 0;
        int result;
        int last = k - 1;
        if (arr[last] == 0) {
            while (arr[last - counter] == 0) {
                counter++;
            }
            result = last - counter - 1;
        } else {
            while (arr[last + counter] == arr[last]) {
                counter++;
            }
            result = last + counter - 1;
        }
        cout << result << endl;
    }
}
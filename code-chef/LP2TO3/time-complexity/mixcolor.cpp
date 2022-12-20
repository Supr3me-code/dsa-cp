#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
            maxi = max(maxi, arr[i]);
        }
        int count = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                arr[i] += maxi;
                maxi = arr[i];
                count++;
            }
        }
        cout << count << endl;
    }
    // your code goes here
    return 0;
}

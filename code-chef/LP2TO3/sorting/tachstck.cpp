#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (abs(arr[i] - arr[i + 1]) <= d) {
            count++;
            i++;
        }
    }
    cout << count << endl;

    // your code goes here
    return 0;
}

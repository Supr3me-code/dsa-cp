#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        int result = 0;
        for (int i = 1; i <= n - 1; i++) {
            // cout<<"HERE: "<<i<<endl;
            for (int j = i + 1; j <= min(n, i + 9); j++) {
                // cout<<"THERE: "<<j<<endl;
                if (abs(arr[i - 1] - arr[j - 1]) == j - i) {
                    result++;
                    // cout<<"EVERYWHERE: "<<result<<endl;
                }
            }
        }
        cout << result << endl;
    }
    // your code goes here
    return 0;
}

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
        vector<int> pfix(n);
        vector<int> sfix(n);
        pfix[0] = arr[0];
        sfix[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) {
            pfix[i] = __gcd(pfix[i - 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            sfix[i] = __gcd(sfix[i + 1], arr[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int final_p = ((i - 1) >= 0 ? pfix[i - 1] : 0);
            int final_s = ((i + 1) < n ? sfix[i + 1] : 0);

            if (__gcd(final_p, final_s) > 1) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
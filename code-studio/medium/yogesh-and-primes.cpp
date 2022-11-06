#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b, k;
        cin >> a >> b >> k;
        int result = -1;
        int noOfPrimes = 0;
        for (int i = a; i <= b; i++) {
            if (isPrime(i)) {
                noOfPrimes++;
            }
            if (noOfPrimes == k) {
                result = i;
                break;
            }
        }
        cout << result << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int LCM = lcm(n, k);
        cout << LCM / k << endl;

    }  // your code goes here
    return 0;
}

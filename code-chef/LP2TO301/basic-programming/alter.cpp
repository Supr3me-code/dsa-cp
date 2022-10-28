#include <bits/stdc++.h>
using namespace std;

bool skillLevel(int a, int b, int p, int q) {
    int Adays = p / a;
    int Bdays = q / b;
    if (p % a != 0 || q % b != 0) return false;
    if (p < a || q < b) return false;
    if (abs(Adays - Bdays) <= 1)
        return true;
    else
        return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;

        if (skillLevel(a, b, p, q))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // your code goes here
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i / 5;
        }
        int counter = 0;

        for (int i = k - 1; i < n - 1; i++) {
            if (arr[i] != arr[i + 1]) {
                counter++;
            }
        }

        cout << counter << endl;
    }
    return 0;
}

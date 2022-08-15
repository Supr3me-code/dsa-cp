#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n - 1];
        for (int i = 0; i < n - 1; i++) {
            cin >> arr[i];
        }

        int cumulative[n - 1];
        cumulative[0] = arr[0];
        for (int i = 1; i < n - 1; i++) {
            cumulative[i] = cumulative[i - 1] + arr[i];
        }

        int result = arr[0];

        for (int i = 0; i < n - 1; i++) {
            if (cumulative[i] > result) {
                result = cumulative[i];
            }
            result += arr[i];
        }
        cout << result << endl;
    }
    return 0;
}
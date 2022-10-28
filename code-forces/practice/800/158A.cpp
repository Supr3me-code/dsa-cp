#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = k - 1;
    if (arr[k - 1] == 0) {
        while (arr[i] == 0) {
            i--;
        }
    } else {
        int counter = 1;
        while (arr[k + counter - 1] == arr[k - 1]) {
            i++;
        }
    }
    cout << i + 1 << endl;
}
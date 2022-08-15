#include <iostream>
using namespace std;

// int findIndexOfSmallestNumber(int arr[], int size) {
//     int smallest = INT_MAX;
//     int index;

//     for (int i = 0; i < size; i++) {
//         if (arr[i] < smallest) {
//             smallest = arr[i];
//             index = i;
//         }
//     }
//     return index;
// }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int idx = 0;  // index of the smallest element
        for (int i = 0; i < y; i++) {
            arr[idx] ^= x;
        }

        sort(arr, arr + n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
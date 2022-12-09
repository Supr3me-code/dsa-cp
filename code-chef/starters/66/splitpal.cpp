#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int start = 0;
        int end = n - 1;
        int counter = 0;
        while (start < end) {
            if (arr[start] == arr[end])
                start++, end--;
            else if (arr[start] > arr[end]) {
                arr[start] = arr[start] - arr[end];
                end--;
                counter++;
            } else {
                arr[end] = arr[end] - arr[start];
                start++;
                counter++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
// This code is contributed by Anjali Saxena

#include <bits/stdc++.h>

using namespace std;

// Function to find position to insert current element of
// stream using binary search
int binarySearch(float arr[], float item, int low, int high) {
    if (low >= high) {
        return (item > arr[low]) ? (low + 1) : low;
    }
    int mid = (low + high) / 2;
    if (item == arr[mid]) return mid + 1;
    if (item > arr[mid]) return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

// Function to print median of stream of integers
void printMedian(float arr[], int n) {
    int i, j, pos;
    float num;
    int count = 1;

    cout << "Median after reading 1"
         << " element is " << arr[0] << "\n";

    for (i = 1; i < n; i++) {
        float median;
        j = i - 1;
        num = arr[i];

        // find position to insert current element in sorted
        // part of array
        pos = binarySearch(arr, num, 0, j);

        // move elements to right to create space to insert
        // the current element
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = num;

        // increment count of sorted elements in array
        count++;

        // if odd number of integers are read from stream
        // then middle element in sorted order is median
        // else average of middle elements is median
        if (count % 2 != 0) {
            median = arr[count / 2];
        } else {
            median = (arr[(count / 2) - 1] + arr[count / 2]) / 2;
        }

        cout << "Median after reading " << i + 1 << " elements is " << median
             << "\n";
    }
}

// Driver Code
int main() {
    float arr[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMedian(arr, n);

    return 0;
}

// This code is modified by Susobhan Akhuli

void streamMed(int A[], int n) {
    // Declared two max heap
    priority_queue<int> g, s;

    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        int temp = s.top();
        s.pop();

        // Negation for treating it as min heap
        g.push(-1 * temp);
        if (g.size() > s.size()) {
            temp = g.top();
            g.pop();
            s.push(-1 * temp);
        }
        if (g.size() != s.size())
            cout << (double)s.top() << "\n";
        else
            cout << (double)((s.top() * 1.0 - g.top() * 1.0) / 2) << "\n";
    }
}



//------------------------------------ through merging


#include <bits/stdc++.h>

void mergeTwoArrays(vector<int> &arr1, vector<int> &arr2, int N1, int N2,
                    vector<int> &arr3) {
    int i = 0, j = 0, k = 0;

    while (i < N1 && j < N2) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < N1) arr3[k++] = arr1[i++];

    while (j < N2) arr3[k++] = arr2[j++];
}

void mergeKArrays(vector<vector<int>> &kArrays, int i, int j,
                  vector<int> &output) {
    if (i == j) {
        for (int m = 0; m < kArrays[i].size(); m++) {
            output[m] = kArrays[i][m];
        }
        return;
    }

    if (j - i == 1) {
        mergeTwoArrays(kArrays[j], kArrays[i], kArrays[j].size(),
                       kArrays[i].size(), output);
        return;
    }

    vector<int> out1, out2;

    mergeKArrays(kArrays, i, (i + j) / 2, out1);
    mergeKArrays(kArrays, (i + j) / 2 + 1, j, out2);

    mergeTwoArrays(out1, out2, out1.size(), out2.size(), output);
}

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {
    vector<int> output;

    mergeKArrays(kArrays, 0, k, output);

    return output;
    // Write your code here.
}

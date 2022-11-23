class Solution {
   public:
    int maxProduct(vector<int>& A) {
        int n = A.size();
        // store the result that is the max we have found so far
        int r = A[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number A[i]
        for (int i = 1, imax = r, imin = r; i < n; i++) {
            // multiplied by a negative makes big number smaller, small number
            // bigger so we redefine the extremums by swapping them
            if (A[i] < 0) swap(imax, imin);

            // max/min product for the current number is either the current
            // number itself or the max/min by the previous number times the
            // current one
            imax = max(A[i], imax * A[i]);
            imin = min(A[i], imin * A[i]);

            // the newly computed max value is a candidate for our global result
            r = max(r, imax);
        }
        return r;
    }
};

#include <bits/stdc++.h>

int maximumProduct(vector<int>& arr, int n) {
    int current = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            current = 1;
            maxi = max(maxi, 0);
        } else {
            current *= arr[i];
            maxi = max(maxi, current);
        }
    }  // Write your code here
    current = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            current = 1;
            maxi = max(maxi, 0);
        } else {
            current *= arr[i];
            maxi = max(maxi, current);
        }
    }
    return maxi;
}

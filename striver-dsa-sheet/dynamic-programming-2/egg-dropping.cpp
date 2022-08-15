class Solution {
   public:
    int arr[201][201];
    int recur(int n, int k) {
        if (k == 0 || k == 1) {
            return 1;
        }
        if (n == 1) {
            return k;
        }
        if (arr[n][k] != -1) {
            return arr[n][k];
        }
        int mn = INT_MAX;
        for (int i = 1; i <= k; i++) {
            int tmp = 1 + max(recur(n - 1, i - 1), recur(n, k - i));
            mn = min(mn, tmp);
        }
        return arr[n][k] = mn;
    }
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        memset(arr, -1, sizeof(arr));
        return recur(n, k);
        // your code here
    }
};
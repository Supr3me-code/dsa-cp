// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

class Solution {
   public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = (double)1 / x;
            n = abs(n);
        }
        double z = 1;
        for (int i = 31; i >= 0; i--) {
            z = (z * z);
            int bit = 1 << i;
            if (n & bit) z = (z * x);
        }
        return z;
    }
};

double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;
    if (nn < 0) nn = -1 * nn;
    while (nn) {
        if (nn % 2) {
            ans = ans * x;
            nn = nn - 1;
        } else {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}
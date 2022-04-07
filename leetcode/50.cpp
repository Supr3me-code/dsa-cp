class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){ x= (double) 1 / x; n = abs(n); }
        double z = 1;
        for(int i=31;i>=0;i--){
            z =(z*z);
            int bit = 1<<i;
            if(n & bit)
                z = (z*x);
        }
        return z;
    }
};
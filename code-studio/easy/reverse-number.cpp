#include <bits/stdc++.h>
long long int reverseNumber(long long int n) {
    long long int result = 0;
    while (n > 0) {
        int x = n % 10;
        result = result * 10 + x;
        n /= 10;
    }
    return result;
    // type your code here
}

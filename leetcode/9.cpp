class Solution {
   public:
    bool isPalindrome(int x) {
        vector<int> arr;
        if (x < 0) return false;
        while (x > 0) {
            arr.push_back(x % 10);
            x /= 10;
        }
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            if (arr[start] != arr[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};

// without extra space

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        while (x > sum) {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};
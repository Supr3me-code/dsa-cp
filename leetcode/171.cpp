class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        int len = columnTitle.size();
        for(int i=0;i<len;i++){
            result += pow(26,i)*(columnTitle[len-i-1]%64);
        }
        return result;
    }
};
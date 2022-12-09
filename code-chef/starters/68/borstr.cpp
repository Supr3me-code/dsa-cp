#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        map<string, int> mp;

        string tmp = "";
        int result = 0;

        for (int i = 0; i <= n; i++) {
            if (i == 0)
                tmp += str[i];
            else if (i == n) {
                mp[tmp] += 1;
                int size = tmp.size();
                if (mp[tmp] > 1)
                    result = max(result, size);
                else
                    result = max(result, size - 1);
            } else {
                if (str[i] == str[i - 1])
                    tmp += str[i];
                else {
                    mp[tmp] += 1;
                    int size = tmp.size();
                    if (mp[tmp] > 1)
                        result = max(result, size);
                    else
                        result = max(result, size - 1);
                    tmp = "";
                    tmp += str[i];
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
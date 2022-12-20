#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int noOfNaps = 0;
        int counter = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') counter++;
            if (counter == k) {
                counter = 0;
                noOfNaps++;
            }
            if (s[i] == '1') counter = 0;
        }
        cout << noOfNaps << endl;
    }
    // your code goes here
    return 0;
}

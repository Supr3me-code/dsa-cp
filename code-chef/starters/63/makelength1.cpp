#include <bits/stdc++.h>
using namespace std;

bool helper(string s, int n) {
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < n; i++) {
        if (st.top() == s[i]) {
            st.pop();
            st.push('0');
        } else
            st.push(s[i]);
    }

    if (st.size() == 1)
        return true;
    else {
        char ch = st.top();
        st.pop();
        while (!st.empty() && st.top() == ch) {
            st.pop();
        }
        if (st.empty())
            return true;
        else
            return false;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (helper(s, n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    // your code goes here
    return 0;
}

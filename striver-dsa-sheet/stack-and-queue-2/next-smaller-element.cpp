vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    vector<int> res;

    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) st.pop();
        if (st.empty())
            res.push_back(-1);
        else
            res.push_back(st.top());
        st.push(A[i]);
    }

    return res;
}

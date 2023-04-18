class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            int currHeight = i == n ? 0 : heights[i];
            while (!st.empty() &&
                   currHeight < heights[st.top()]) {  // if sequence decreases
                int top = st.top();
                st.pop();  // now we check rectangle of each height before the
                           // point when smaller building came
                int width = st.empty() ? i : i - st.top() - 1;
                int area = heights[top] * width;
                maxArea = max(area, maxArea);
            }

            st.push(i);  // if increasing sequence is maintained
        }
        return maxArea;
    }
};

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];

    // finding the first smaller height on the left of current bar
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
    }

    // to re-use the stack
    while (!st.empty()) st.pop();

    // finding the first smaller height on the right of current bar
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;
        st.push(i);
    }

    int maxA = 0;
    for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
} 
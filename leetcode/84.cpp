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
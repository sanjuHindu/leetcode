class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] > currHeight) {
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
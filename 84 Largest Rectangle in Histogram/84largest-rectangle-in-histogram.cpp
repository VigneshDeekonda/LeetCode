class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<int> s;
        // right side traversal
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        // left side
        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int w = right[i] - left[i] - 1;
            int currsum = heights[i] * w;
            ans = max(ans, currsum);
        }
         return ans;
    }
};
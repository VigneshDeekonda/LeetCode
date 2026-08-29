class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> mp(n);
        for (int i = 2 * n - 1; i >= 0; i--) {
            int ind = i % n;
            int currEle = nums[ind];
            while (!st.empty() && st.top() <= currEle) {
                st.pop();
            }
            if (i < n) {
                mp[i] = st.empty() ? -1 : st.top();
            }
            st.push(currEle);
        }
        return mp;
    }
};
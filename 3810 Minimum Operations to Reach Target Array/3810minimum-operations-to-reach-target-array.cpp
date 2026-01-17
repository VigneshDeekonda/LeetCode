class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == target[i]) {
                continue;
            } else {
                st.insert(nums[i]);
            }
        }

        return st.size();
    }
};

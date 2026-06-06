class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        vector<int> ans(n);
        int left_sum = 0;

        for (int i = 0; i < n; i++) {
            int right_sum = totalSum - left_sum - nums[i];
            ans[i] = abs(left_sum - right_sum);
            left_sum += nums[i];
        }
        return ans;
    }
};
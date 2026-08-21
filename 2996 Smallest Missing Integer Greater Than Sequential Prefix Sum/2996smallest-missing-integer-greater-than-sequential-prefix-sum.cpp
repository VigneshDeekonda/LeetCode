class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] == 1) {
                sum += nums[i + 1];
            } else {
                break;
            }
        }

        int ans = sum;

        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] == ans) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return ans;
            }
            ans++;
        }
    }
};
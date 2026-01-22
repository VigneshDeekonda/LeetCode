class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (!is_sorted(nums.begin(), nums.end())) {
            int minSum = INT_MAX;
            int idx = 0;

            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            // Replace the pair with their sum
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);

            count++;
        }

        return count;
    }
};

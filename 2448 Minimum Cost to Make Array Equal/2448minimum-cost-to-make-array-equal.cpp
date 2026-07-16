class Solution {
public:
    long long costelement(vector<int>& nums, vector<int>& cost, int target) {
        long long result = 0;
        for (int i = 0; i < nums.size(); ++i) {
          result += 1LL * abs(nums[i] - target) * cost[i];
                }
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long answer = INT_MAX;
        long long left = *min_element(begin(nums), end(nums));
        long long right = *max_element(begin(nums), end(nums));

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long costA = costelement(nums, cost, mid);
            long long costB = costelement(nums, cost, mid + 1);
            answer = min(costA, costB);
            if (costA > costB) {
                left = mid + 1;
            } else {
              right =  mid -1;
            }
        }
        return answer ==INT_MAX ?0:answer;
    }
};

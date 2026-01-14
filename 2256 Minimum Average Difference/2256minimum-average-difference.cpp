class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        // Total sum
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        long long LS = 0, RS = 0;
        long long result = LLONG_MAX;
        int index = 0;

        for (int i = 0; i < n; i++) {
            LS += nums[i];
            RS = sum - LS;

            int n1 = i + 1;
            int n2 = n - n1;

            long long left_avg = LS / n1;
            long long right_avg = (n2 == 0) ? 0 : RS / n2;

            long long diff = llabs(left_avg - right_avg);

            if (diff < result) {
                result = diff;
                index = i;
            }
        }

        return index;
    }
};

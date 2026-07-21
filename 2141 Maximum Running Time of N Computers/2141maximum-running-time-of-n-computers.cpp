class Solution {
public:
    bool possible(int n, vector<int>& batteries, long long mid_element) {
        long long target_min = 1LL * n * mid_element;
        long long sum = 0;

        for (int i = 0; i < batteries.size(); i++) {
            sum += min((long long)batteries[i], mid_element);

            if (sum >= target_min)
                return true;
        }

        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {

        long long l = *min_element(begin(batteries), end(batteries));

        long long sum_total = 0;
        for (auto &battery : batteries)
            sum_total += battery;

        long long r = sum_total / n;
        long long result = 0;

        while (l <= r) {
            long long mid_element = l + (r - l) / 2;

            if (possible(n, batteries, mid_element)) {
                result = mid_element;
                l = mid_element + 1;
            } else {
                r = mid_element - 1;
            }
        }

        return result;
    }
};
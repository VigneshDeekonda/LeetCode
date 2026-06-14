class Solution {
public:
    long long backToNumber(string& binary) {
        long long result = 0;
        for (int i = 0; i < binary.size(); i++) {
            result = result * 2 + (binary[i] - '0');
        }
        return result;
    }

    int Convert(int x) {
        string s;
        while (x) {
            int d = x % 2;
            s += to_string(d);
            x /= 2;
        }
        int y = backToNumber(s);
        return y;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> hold;
        for (int i = 0; i < n; i++) {
            int x = Convert(nums[i]);
            pq.push({x, nums[i]});
        }
        while (!pq.empty()) {
            hold.push_back(pq.top().second);
            pq.pop();
        }
        return hold;
    }
};
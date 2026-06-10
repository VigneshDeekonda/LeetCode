class Solution {
    vector<pair<int,int>> seg;

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[idx] = {nums[l], nums[l]};
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * idx + 1, l, mid, nums);
        build(2 * idx + 2, mid + 1, r, nums);

        seg[idx].first = min(seg[2 * idx + 1].first,
                             seg[2 * idx + 2].first);

        seg[idx].second = max(seg[2 * idx + 1].second,
                              seg[2 * idx + 2].second);
    }

    pair<int,int> query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return {INT_MAX, INT_MIN};

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = l + (r - l) / 2;

        auto left = query(2 * idx + 1, l, mid, ql, qr);
        auto right = query(2 * idx + 2, mid + 1, r, ql, qr);

        return {
            min(left.first, right.first),
            max(left.second, right.second)
        };
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        seg.resize(4 * n);
        build(0, 0, n - 1, nums);

        priority_queue<tuple<int,int,int>> pq;

        for (int start = 0; start < n; start++) {
            auto [mn, mx] = query(0, 0, n - 1, start, n - 1);
            pq.push({mx - mn, start, n - 1});
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r - l > 1) {
                auto [mn, mx] = query(0, 0, n - 1, l, r - 1);
                pq.push({mx - mn, l, r - 1});
            }
        }

        return ans;
    }
};
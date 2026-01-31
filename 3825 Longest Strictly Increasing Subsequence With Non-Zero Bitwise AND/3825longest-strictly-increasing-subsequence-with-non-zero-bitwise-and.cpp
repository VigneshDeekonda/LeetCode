class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            vector<int> lis;

            for (int num : nums) {
                if (num & (1 << bit)) {
                    auto it = lower_bound(lis.begin(), lis.end(), num);

                    if (it == lis.end())
                        lis.push_back(num);
                    else
                        *it = num;
                }
            }
            ans = max(ans, (int)lis.size());
        }
        return ans;
    }
};
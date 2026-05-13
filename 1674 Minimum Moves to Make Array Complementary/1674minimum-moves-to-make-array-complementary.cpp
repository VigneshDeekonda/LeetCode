class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, int> allsums;
        for (int i = 0; i < nums.size() / 2; i++) {
            allsums[nums[i] + nums[n - i - 1]]++;
        }
        vector<int> omove(2 * limit + 2, 0), tmove(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int mis = min(nums[i], nums[n - i - 1]) + 1;
            int mas = max(nums[i], nums[n - i - 1]) + limit;
            omove[mis]++;
            omove[mas + 1]--;
            tmove[mas + 1]++;
            tmove[2 * limit + 1]--;
            tmove[2]++;
            tmove[mis]--;
        }
        for (int i = 1; i < omove.size(); i++) {
            omove[i] += omove[i - 1];
            tmove[i] += tmove[i - 1];
        }
        for (auto i : allsums) {
            omove[i.first] -= i.second;
        }
        int mm = INT_MAX;
        for (int i = 2; i < omove.size() - 1; i++) {
            mm = min(omove[i] + 2 * tmove[i], mm);
        }
        return mm;
    }
};
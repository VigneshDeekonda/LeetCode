class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxelement = INT_MIN;
        int minelement = INT_MAX;

        for( int &num : nums){
          maxelement = max(maxelement,num);
          minelement = min(minelement,num);
        }
        return 1L * k * (maxelement-minelement);
    }
};
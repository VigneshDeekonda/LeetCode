class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        if(nums.size()<2) return 0;
        
        long long prefixsum = 0;
        for(int i=0;i<nums.size();i++){
            prefixsum += nums[i];
            
        }
        
        long long Minimumright = nums[nums.size()-1];
        long long score = INT_MIN;
        
        for(int i = nums.size() - 2 ; i >= 0 ; i--)
            {
                prefixsum = prefixsum - nums[i+1];
                score = max(score,prefixsum-Minimumright);
                Minimumright = min(Minimumright,(long long)nums[i]);
            }
        return score;
    }
};
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        for(int i = 1; i < m;i++){
            for(int j = 1;j<n;j++){
                if(nums[i][j]!=nums[i-1][j-1])
                {
                    return false;
                }
            }
        }
          return true;
    }
};
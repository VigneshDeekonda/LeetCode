class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0; 
        int maxi = 0;

        for (int x : nums) {
            if (x == 1) {
                count++;              // increase streak
                maxi = max(maxi, count);
            } else {
                count = 0;            // reset streak
            }
        }

        return maxi;
    }
};
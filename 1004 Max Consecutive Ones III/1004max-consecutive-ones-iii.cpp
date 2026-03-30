class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int zeros = 0;
        int maxlength = 0;

        while(right < nums.size()){

        if(nums[right]==0){
            zeros++;
        }

        if(zeros>k){
            if(nums[left]==0) zeros--;
            left++;
        }
            int len = right-left+1;
            maxlength = max(maxlength,len);
            right++;
        }
        return maxlength;
    }
};
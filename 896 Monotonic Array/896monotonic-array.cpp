class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        
            bool Increasing = false;
            bool Decreasing = false;


        for (int i = 0 ; i < n-1;i++){

            if(nums[i]<nums[i+1])
            Increasing = true;

            if(nums[i]>nums[i+1])
            Decreasing = true;
        }

        if(Increasing == true && Decreasing ==true)
            return false;

            return true;
    }
};
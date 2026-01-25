class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        if(k==1)
        return 0;

        sort(nums.begin(),nums.end());

        int answer = INT_MAX;
        for(int i = 0 ; i <= n-k ; i++){
            int minvalue = nums[i];
            int maxvalue = nums[i+k-1];
            int difference = maxvalue - minvalue;
            answer = min(answer,difference);
        }
        return answer;
    }
};
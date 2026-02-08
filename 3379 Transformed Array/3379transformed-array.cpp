class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n,0);

        for (int i = 0; i < n; i++) {
           int shift = nums[i] % n;

           int newindex = (i + shift) % n;

           if(newindex < 0){
           newindex += n;
           }

           result[i]=nums[newindex];
        }
        return result;
    }
};
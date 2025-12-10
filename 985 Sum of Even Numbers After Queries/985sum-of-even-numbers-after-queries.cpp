class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int sumlenght = 0;
        vector<int> result;

        //for sumofeven
        for(int i = 0 ; i < n; i++){
            if(nums[i]%2==0){
                sumlenght += nums[i];
            }
        }
        //
        for(int i = 0 ; i < q ; i++){
            int val = queries[i][0];
            int idx = queries[i][1];

            if(nums[idx]%2==0){
                sumlenght -= nums[idx];
            }
            nums[idx]+=val;
            
            if(nums[idx]%2==0){
                  sumlenght += nums[idx];
            }
                  result.push_back(sumlenght);
        }
return result;
    }
};
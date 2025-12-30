class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0;i < n;i++){
            sum += nums[i];
        }

        int cs = 0;

        for (int i = 0;i<n;i++){

        int ls  = cs;

        int rs = sum - cs - nums[i];

        if(ls == rs)
        return i;

            cs=cs + nums[i];
            
        }
        return -1;
    }
};



// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();

//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++) {
//         sum = sum + nums[i]; }

//         int cs = 0;
        
//         for(int i = 0; i<n;i++){
//             int ls = cs;
//             int rs = sum-cs-nums[i];

//             if( ls==rs)
//                 return i;

//                 cs=cs + nums[i];
//         }        
//         return -1;
//     }
// };
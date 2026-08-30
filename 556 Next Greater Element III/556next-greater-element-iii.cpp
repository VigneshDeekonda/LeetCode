class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>nums;
        while(n>0){
            nums.push_back(n%10);
            n/=10;
        }

        reverse(nums.begin(), nums.end());
        n= nums.size();
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }

        if(index==-1)return -1;

        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());

        long long sum=0;
        for(int i:nums){
            sum= sum*10+i;
        }
        if(sum>INT_MAX)return -1;
        return sum;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int,int>key;
      for(int x : nums){
        key[x]++;
      }  
      for(auto num : key){
        if(num.second > 1){
            return true;
        }
      }
      return false;
    }
};
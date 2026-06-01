class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost),end(cost),greater<int>());
        int target = 0;
        int n = cost.size();
        for(int i = 0;i<n;i++){
          if(i%3 != 2){
            target+=cost[i];
          }
        }
        return target;
    }
};
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int cx = center[0];
        int cy = center[1];

        int result = -1;
        vector<int>ans = {-1 , -1};

        for(auto &a : towers){
            int x = a[0], y = a[1] , z = a[2];

            int distance = abs( x - cx) + abs(y-cy);

            if(distance<=radius){
                if(z > result || ( z == result && (x < ans[0] || (x ==ans[0] && y < ans[1])))) {
                    result = z;
                    ans={x,y};
                }
            }
        }
        return ans;
    }
};
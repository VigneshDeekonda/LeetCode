class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int , vector<int>> mp ;

        vector<int> result ;

        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flip = true;

      for (int d = 0; d < m + n - 1; d++) {
            if (flip) {
                reverse(mp[d].begin(), mp[d].end());
            }

            for (int num : mp[d]) {
                result.push_back(num);
            }

            flip = !flip;
        }

        return result;
    }
};
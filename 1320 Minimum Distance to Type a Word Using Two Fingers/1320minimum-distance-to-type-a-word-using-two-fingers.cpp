class Solution {
public:
    int dp[301][27][27];

    pair<int, int> getCoord(int pos) {
        return {pos/6, pos%6};
    }

    int getDistance(int pos1, int pos2) {
        if (pos1 == 26 || pos2 == 26) return 0;

        auto [x1, y1] = getCoord(pos1);
        auto [x2, y2] = getCoord(pos2);
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.length();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(27, vector<int>(27, 0)));


        for (int i = n - 1; i >= 0; i--) {
            int curr = word[i] - 'A';

            for (int f1 = 0; f1 < 27; f1++) {
                for (int f2 = 0; f2 < 27; f2++) {

                
                    if (f1 == 26 && f2 == 26) {
                        dp[i][f1][f2] = dp[i+1][curr][f2];
                        continue;
                    }

                    //F2 not used
                    if (f2 == 26) {
                        int moveF2 = dp[i+1][f1][curr]; //solve(i+1, f1, curr);
                        int moveF1 = getDistance(f1, curr) + dp[i+1][curr][f2]; //solve(i+1, curr, f2);

                        dp[i][f1][f2] = min(moveF1, moveF2);
                        continue;
                    }
                    int moveF1 = getDistance(f1, curr) + dp[i+1][curr][f2]; 
                    int moveF2 = getDistance(f2, curr) + dp[i+1][f1][curr]; 
                    dp[i][f1][f2] = min(moveF1, moveF2);
                }
            }
        }

        return dp[0][26][26]; 
    }
};

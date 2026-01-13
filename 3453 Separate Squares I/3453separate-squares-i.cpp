class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = -1e9;
        

        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

       
        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2.0;
            double below = 0, above = 0;

            for (auto &s : squares) {
                double y = s[1];
                double len = s[2];
                double top = y + len;

                if (mid <= y) {
                 
                    above += len * len;
                } 
                else if (mid >= top) {
                    
                    below += len * len;
                } 
                else {
                    
                    double h1 = mid - y;  
                    double h2 = top - mid;  
                    below += h1 * len;
                    above += h2 * len;
                }
            }

            if (below < above)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();    // row
        int n = matrix[0].size(); // Col

        bool firstRowImpact = false;
        bool firstColImpact = false;

        // row mai aaya hai kya 0
        for (int col = 0; col < n; col++) {
            if (matrix[0][col] == 0) {
                firstRowImpact = true;
                break;
            }
        }
        // column mai aaya hai kya 0
        for (int row = 0; row < m; row++) {
            if (matrix[row][0] == 0) {
                firstColImpact = true;
                break;
            }
        }
        // matrix ki value ko set kiya
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowImpact) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColImpact) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
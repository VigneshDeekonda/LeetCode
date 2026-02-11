class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            return {};
        }
        int m = n;
        vector<vector<int>> matrix(m, vector<int>(n));

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        int dir = 0;
        int counter = 1;

        while (top <= bottom && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    matrix[top][i] = counter++;
                }
                top++;
            }
            
            if (dir == 1) {
                for (int i = top; i <= bottom; i++) {
                    matrix[i][right] = counter++;
                }
                right--;
            } 
            if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = counter++;
                }
                bottom--;
            } 
            if (dir == 3) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = counter++;
                }
                left++;
            }

            dir = (dir + 1) % 4;
        }

        return matrix;
    }
};
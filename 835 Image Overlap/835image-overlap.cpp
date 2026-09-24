class Solution {
public:
    int CountOverlaps(vector<vector<int>>& A, vector<vector<int>>& B,int rowOffset, int collOffset) {
        int n = A.size();
        int count = 0;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n; j++) {

                int B_i = i + rowOffset;
                int B_j = j + collOffset;

                if (B_i < 0 || B_i >= n || B_j < 0 || B_j >= n)
                    continue;

                if (A[i][j] == 1 && B[B_i][B_j] == 1)
                    count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int MaxOverlap = 0;
        for (int rowOffset = -n + 1; rowOffset < n; rowOffset++) {
            for (int collOffset = -n + 1; collOffset < n; collOffset++) {
                int count = CountOverlaps(A, B, rowOffset, collOffset);
                MaxOverlap= max(MaxOverlap, count);
            }
        }
        return MaxOverlap;
    }
};
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = 1, count = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
            maxH = max(maxH, count);
        }

        int maxV = 1;
        count = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }
            maxV = max(maxV, count);
        }

        int side = min(maxH + 1, maxV + 1);

        return side * side;
    }
};

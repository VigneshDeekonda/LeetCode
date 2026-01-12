class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totaltime = 0;
        int nums = points.size();
        for(int i = 1 ; i < nums ; i++){
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);
            totaltime += max(dx,dy);
        }
          return totaltime;
    }
};
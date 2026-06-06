class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long bulbs = (brightness+2)/3;

      sort(intervals.begin(),intervals.end());

      long long actTime = 0;
      long long l = intervals[0][0];
      long long r = intervals[0][1];

      for(int i = 1;i<intervals.size();i++){
        long long c = intervals[i][0];
        long long q = intervals[i][1];
        if(c<=r+1){
          r = max(r,q);
        } else {
          actTime += r-l+1;
          l=c;
          r = q;
        }
      }
      actTime+=r-l+1;
      return bulbs*actTime;
    }
};
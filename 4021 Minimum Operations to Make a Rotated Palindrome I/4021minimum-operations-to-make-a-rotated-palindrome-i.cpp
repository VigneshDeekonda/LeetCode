class Solution {
public:
    int minOperations(string s) {
      int ans = INT_MAX;
      int n = s.size();

      for(int i = 0;i<n;i++){
        string a = s.substr(i) + s.substr(0,i);

        int cost = i;

        for(int i = 0 ; i < n/2;i++){
          int x = a[i] - 'a';
          int y = a[n-1-i] - 'a';

          int diff = abs(x - y);
          cost += min(diff,26-diff);
        }
        ans = min(ans,cost);
      }
      return ans;
    }
};
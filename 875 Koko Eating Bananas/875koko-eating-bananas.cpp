class Solution {
public:
bool canEat(vector<int>&piles, int mid,int h){
  int maxcount = 0;
  for( int &x : piles){
    maxcount += x/mid;
    if(x%mid != 0){
      maxcount++;
    }
  }
  return maxcount<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1;
        int r = *max_element(begin(piles), end(piles));
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canEat(piles, mid, h)) {
            r = mid;
            } else {
            l = mid + 1;
            }
        }
        return l;
    }
};
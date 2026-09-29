class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0)
    return false;

    long long div = 1;
     
     while (x>=10*div)
     div = div * 10;
      while (x > 0){
        int first = x/div;
        int last = x%10;

        if ( first!=last)
        return false;

        x = (x % div) / 10;
        div = div/100;
      }
      return true;
    }
};
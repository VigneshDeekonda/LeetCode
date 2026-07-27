class Solution {
public:
    int maxProduct(int n) {
        int maxDigit = 0;
        int SecondMaxDigit = 0;
        while (n > 0) {
          int r = n % 10;
            if (maxDigit < r) {
                SecondMaxDigit = maxDigit;
                maxDigit = r;
            } else if (SecondMaxDigit < r) {
                SecondMaxDigit = r;
            }
            n /= 10;
        }
        return maxDigit * SecondMaxDigit;
    }
};
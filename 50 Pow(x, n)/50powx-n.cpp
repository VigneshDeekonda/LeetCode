class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;      // convert to long long to handle INT_MIN
        if (N < 0) {
            x = 1 / x;        // x^-n = (1/x)^n
            N = -N;
        }

        double ans = 1.0;

        while (N > 0) {
            if (N % 2 == 1) { // if power is odd
                ans = ans * x;
            }
            x = x * x;        // square the base
            N = N / 2;        // reduce power by half
        }

        return ans;
    }
};
class Solution {
public:
    int findFourDivisors(int num) {
        int sum = 0;
        int divisors = 0;

        for (int fact = 1; fact * fact <= num; fact++) {
            if (num % fact == 0) {
                int other = num / fact;

                if (fact == other) {
                    divisors += 1;
                    sum += fact;
                } else {
                    divisors += 2;
                    sum += fact + other;
                }

                if (divisors > 4) return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result += findFourDivisors(num);
        }
        return result;
    }
};
// class Solution {
//   public:       
//         const int INT_MIN_VAL = -2147483648;
//         const int INT_MAX_VAL = 2147483647;

// int helper(const string &s, int i, long long num, int sign) {
//     if (i >= s.size() || !isdigit(s[i]))
//         return (int)(sign * num);
//     num = num * 10 + (s[i] - '0');
//     if (sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
//     if (sign * num >= INT_MAX_VAL) return INT_MAX_VAL;
//     return helper(s, i + 1, num, sign);
// }

// int myAtoi(string &s, int i = 0) {
//     while (i < s.size() && s[i] == ' ') i++;
//     int sign = 1;
//     if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
//         sign = (s[i] == '-') ? -1 : 1;
//         i++;
//     }
//     return helper(s, i, 0, sign);
// }
// };


class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        // 1. Skip spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // 4. Handle overflow
            if (sign * result > INT_MAX) return INT_MAX;
            if (sign * result < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * result;
    }
};
class Solution {
public:
    int waviness(int num) {
        int count = 0;
        string s = to_string(num);

        for (int i = 1; i < (int)s.size() - 1; i++) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                count++;
            }
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int num = num1; num <= num2; num++){
          ans += waviness(num);
        }
        return ans;
    }
};
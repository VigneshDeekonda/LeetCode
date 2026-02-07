class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0;
        int result = 0;
        for (char& c : s) {
            if (c == 'b') {
                count++;
            } else {
                if (count > 0) {
                    result++;
                    count--;
                }
            }
        }
        return result;
    }
};
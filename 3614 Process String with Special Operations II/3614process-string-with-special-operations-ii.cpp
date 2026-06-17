class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (len > 0)
                    len--;
            } else if (s[i] == '#') {
                len = len * 2;
            } else if (s[i] == '%') {
                continue;
            } else {
                len++;
            }
        }

        if (k >= len)
            return '.';
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                len++;
            } else if (s[i] == '%') {
                k = len - k - 1;
            } else if (s[i] == '#') {
                len = len / 2;
                if(k>= len) k = k-len;
            } else {
                len--;
                if (len == k)
                    return s[i];
            }
        }
        return '.';
    }
};
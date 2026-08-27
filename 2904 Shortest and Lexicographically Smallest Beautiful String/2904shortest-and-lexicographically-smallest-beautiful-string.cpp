class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count = 0;
        int n = s.size();
        int left = 0;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                count++;

            while (count > k) {
                if (s[left] == '1')
                    count--;
                left++;
            }

            while (count == k && s[left] == '0') {
                left++;
            }
            if (count == k) {
                string current = s.substr(left, right - left + 1);

                if (ans == "" || current.size() < ans.size() ||
                    (current.size() == ans.size() && current < ans)) {
                    ans = current;
                }
            }
        }

        return ans;
    }
};
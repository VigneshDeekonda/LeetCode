class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int left = 0;
        unordered_map<char, int> char_set = {{'a', 0}, {'b', 0}, {'c', 0}};
        for (int right = 0; right < s.length(); right++) {
            char_set[s[right]]++;
            while (char_set['a'] > 0 && char_set['b'] > 0 &&
                   char_set['c'] > 0) {
                count += s.length() - right;
                char_set[s[left]]--;
                left++;
            }
        }
        return count;
    }
};

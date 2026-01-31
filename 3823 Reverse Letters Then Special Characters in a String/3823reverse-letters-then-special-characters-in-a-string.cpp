class Solution {
public:
    string reverseByType(string s) {
        vector<char> letters, specials;

        // Step 1: Separate characters
        for (char c : s) {
            if (c >= 'a' && c <= 'z')
                letters.push_back(c);
            else
                specials.push_back(c);
        }

        // Step 2: Two pointers from the end
        int i = letters.size() - 1;
        int j = specials.size() - 1;

        // Step 3: Rebuild the string
        for (int k = 0; k < s.size(); k++) {
            if (s[k] >= 'a' && s[k] <= 'z')
                s[k] = letters[i--];
            else
                s[k] = specials[j--];
        }

        return s;
    }
};

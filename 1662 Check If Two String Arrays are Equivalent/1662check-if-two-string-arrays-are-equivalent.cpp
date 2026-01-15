class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        // Step 1: Create two empty strings
        string s1 = "";
        string s2 = "";

        // Step 2: Concatenate all strings from word1 into s1
        for (int i = 0; i < word1.size(); i++) {
            s1 += word1[i];
        }

        // Step 3: Concatenate all strings from word2 into s2
        for (int i = 0; i < word2.size(); i++) {
            s2 += word2[i];
        }

        // Step 4: Compare the final strings
        if (s1 == s2)
            return true;
        else
            return false;
    }
};

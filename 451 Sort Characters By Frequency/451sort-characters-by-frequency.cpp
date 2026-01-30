class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Store characters and their frequencies
        vector<pair<char, int>> chars;
        for (auto it : freq) {
            chars.push_back(it);
        }

        // Step 3: Sort characters by frequency (descending)
        sort(chars.begin(), chars.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Step 4: Build the result string
        string result = "";
        for (auto &p : chars) {
            result.append(p.second, p.first);
        }

        return result;
    }
};

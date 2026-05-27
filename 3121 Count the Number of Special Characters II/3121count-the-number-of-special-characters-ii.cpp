class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        int count = 0;

        vector<int> lowercase(26, -1);
        vector<int> uppercase(26, -1);

        for (int i = 0; i < n; i++) {
            char ch = word[i];

            if (islower(ch)) {
                lowercase[ch - 'a'] = i;
            } else {
                if (uppercase[ch - 'A'] == -1) {
                    uppercase[ch - 'A'] = i;
                }
            }
        }
        for(int i = 0 ; i < 26 ;i++){
            if(lowercase[i] != -1 && uppercase[i] != -1 && lowercase[i] < uppercase[i]){
                count++;
            }
        }
        return count;
    }
};
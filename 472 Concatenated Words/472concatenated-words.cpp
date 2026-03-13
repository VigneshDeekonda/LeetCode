class Solution {
public:
    unordered_map<string,bool> memo;

    bool isConcatenated(string word, unordered_set<string>& st){
        if(memo.count(word)) return memo[word];

        for(int i=1;i<word.size();i++){
            string prefix = word.substr(0,i);
            string suffix = word.substr(i);

            if(st.count(prefix)){
                if(st.count(suffix) || isConcatenated(suffix,st)){
                    return memo[word] = true;
                }
            }
        }

        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        vector<string> result;

        for(string &word:words){
            st.erase(word);

            if(isConcatenated(word,st)){
                result.push_back(word);
            }

            st.insert(word);
        }

        return result;
    }
};
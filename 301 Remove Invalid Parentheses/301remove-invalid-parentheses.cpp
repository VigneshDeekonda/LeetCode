class Solution {
public:
    vector<string> ans;

    void solve(string s, int start, int lradius, int rradius) {
        if (lradius == 0 && rradius == 0) {
            if (isValid(s))
                ans.push_back(s);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (i > start && s[i] == s[i - 1])
                continue;
            if (lradius > 0 && s[i] == '(') {
                string t = s.substr(0, i) + s.substr(i + 1);
                solve(t, i, lradius - 1, rradius);
            }
            if (rradius > 0 && s[i] == ')') {
                string t = s.substr(0, i) + s.substr(i + 1);
                solve(t, i, lradius, rradius - 1);
            }
        }
    }

    bool isValid(string s) {
        int balance = 0;
        for (char ch : s) {
            if (ch == '(')
                balance++;
            else if (ch == ')') {
                balance--;
                if (balance < 0)
                    return false;
            }
        }
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        int lradius = 0;
        int rradius = 0;
        for (char c : s) {
            if (c == '(') {
                lradius++;
            } else if (c == ')'){
                    if (lradius > 0)
                    lradius--;
                else
                    rradius++;
            }
        }
        solve(s, 0, lradius, rradius);
        return ans;
    }
};
class Solution {
public:
    int n;
    vector<string> result;

    bool isvalid(string str) {
        if (str.length() > 1 && str[0] == '0')
            return false;

        int val = stoi(str);
        return val <= 255;
    }

    void solve(string& s, int idx, int parts, string curr) {

        if (idx == n && parts == 4) {
            result.push_back(curr.substr(0, curr.length() - 1));
            return;
        }

        if (parts >= 4) return;

        if (idx + 1 <= n) {
            solve(s, idx + 1, parts + 1, curr + s.substr(idx, 1) + ".");
        }

        if (idx + 2 <= n && isvalid(s.substr(idx, 2))) {
            solve(s, idx + 2, parts + 1, curr + s.substr(idx, 2) + ".");
        }

        if (idx + 3 <= n && isvalid(s.substr(idx, 3))) {
            solve(s, idx + 3, parts + 1, curr + s.substr(idx, 3) + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        result.clear();

        if (n > 12)
            return {};

        solve(s, 0, 0, "");

        return result;
    }
};
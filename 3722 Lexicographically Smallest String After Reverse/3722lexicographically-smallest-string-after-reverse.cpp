class Solution {
public:
    string lexSmallest(string s) {
        string best = s;
        int n = s.size();
        for (int i = 1;i<=n;i++){
            string temp1 = s;
            reverse(temp1.begin(),temp1.begin()+i);
            best = min(best,temp1);
            string temp2 = s;
            reverse(temp2.end()-i,temp2.end());
             best = min(best,temp2);
        }
        return best;
    }
};
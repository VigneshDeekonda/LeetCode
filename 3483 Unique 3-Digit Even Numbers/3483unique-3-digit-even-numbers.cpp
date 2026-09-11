class Solution{
    public:
        int totalNumbers(vector<int>& digits) {
            int n = digits.size();
            unordered_set<int>seen;
            for(int h = 0; h<n;h++){
                if(digits[h] == 0) continue;
                for(int t = 0; t <n ;t++){
                    if(h==t) continue;
                    for(int u=0;u<n;u++){
                        if(h==u || t==u) continue;
                        if(digits[u] %2 !=0 ) continue;
                        int num = digits[h]*100+digits[t]*10+digits[u];
                        seen.insert(num);
                    }
                }
            }
            return seen.size();
        }
};
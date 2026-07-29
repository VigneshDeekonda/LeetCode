class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;

        while(i>=0){
        if(digits[i] < 9){
          digits[i]++;
          return digits;
        }

        digits[i] = 0; // to handel the case like 289 229 etc
        i--;
        }
        digits.insert(digits.begin(),1); // to handel 999
        return digits;
    }
};
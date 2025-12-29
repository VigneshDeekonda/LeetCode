class Solution {
public:
bool isAlpaNum(char ch){
    if((ch >= '0' &&  ch <='9') || 
    (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
{
    return true;
}
return false;
}
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size()-1;

        while(end > st){
            if(!isAlpaNum(s[st])){
                st++; continue;
            }
             if(!isAlpaNum(s[end])){
               end--; continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;

        }
        return true;
    }
};
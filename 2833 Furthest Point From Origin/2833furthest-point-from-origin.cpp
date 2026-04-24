class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int Left= 0; 
        int Right = 0;
        int count = 0;

        for (char c : moves){
            if(c =='L') Left++;
            else if (c == 'R') Right++;
            else count++;
        }
        return abs(Left - Right)+ count;
    }
};
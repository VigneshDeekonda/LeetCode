class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n  = words.size();

        int result = INT_MAX;

        for ( int i = 0 ; i < n ; i++){
            if( words [i] == target){
                int strainghtdist = abs(i-startIndex);
                int circulardist = n-strainghtdist;

                result = min({result,strainghtdist,circulardist});

            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
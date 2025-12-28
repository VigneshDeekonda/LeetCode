class Solution {
public:
    int minAllOneMultiple(int k) {
        vector<char>visited(k,0);

        int leftover = 0;

        for(int number = 1; number <= k; number++){
            leftover = (leftover * 10 + 1) % k;

            if(leftover == 0)
                return number;

            if(visited[leftover])
                break;

            visited[leftover] = 1;
        }
        return -1;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;

        // Take first k elements from left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxsum = lsum;

        int rightIndex = n - 1;

        // Replace left elements with right elements
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];          // remove from left
            rsum += cardPoints[rightIndex]; // add from right
            rightIndex--;

            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxwater = 0;

        while(left < right){
            int w = right - left;
            int ht = min(height[left], height[right]);
            maxwater = max(maxwater, w * ht);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxwater;
    }
};
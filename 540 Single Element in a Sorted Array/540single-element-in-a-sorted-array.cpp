class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            bool isEven;
            if ((right - mid) % 2 == 0) {
                isEven = true;
            } else {
                isEven = false;
            }

            if (nums[mid] == nums[mid + 1]) {
                if (isEven) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // nums[mid] != nums[mid + 1] wala case
                if (isEven) {
                  right = mid;
                } else {
                  left = mid + 1;
                }
            }
        }
        return nums[right];
    }
};
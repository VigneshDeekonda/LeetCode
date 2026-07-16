class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            while (left < right && nums[left] == nums[left + 1])
                left++;

            while (right > left && nums[right] == nums[right - 1])
                right--;
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }
            // for same and repeated values so muje repeated values ko delte
            // karne padhega

            // left side is smaller than the mid this means that right is sorted
            // example [6(l),7,8,9,1(mid),2,3,4,5(r)]
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }

            } else {
                // right side is sorted means mid is smaller than right
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
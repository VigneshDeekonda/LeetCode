class Solution {
public:
    int findthefleftmost(vector<int>& nums, int target, int n) {
        int left = 0;
        int right = nums.size() - 1;
        int left_most = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left_most = mid;
                right = mid - 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left_most;
    }

    int findtherightmost(vector<int>& nums, int target, int n) {

        int left = 0;
        int right = nums.size() - 1;
        int right_most = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                right_most = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right_most;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      int n = nums.size();
      int right_most = findtherightmost(nums,target,n);
      int left_most = findthefleftmost(nums,target,n);
      return{left_most,right_most};
    }
};

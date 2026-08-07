class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (int i = 0; i < n; i++) {
          int x = nums[i];
            if (minheap.size() < k) {
                minheap.push(x);
            } else if(nums[i]>minheap.top()){
              minheap.pop();
              minheap.push(x);
            }
        }
        return minheap.top();
    }
};
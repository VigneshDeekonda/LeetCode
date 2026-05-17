class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);

        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty()) {
            int index = q.front();
            q.pop();

            if (arr[index] == 0) {
                return true;
            }

            int forward = index + arr[index];
            int backward = index - arr[index];

            if (forward >= 0 && forward < n && !visited[forward]) {
                q.push(forward);
                visited[forward] = 1;
            }

            if (backward >= 0 && backward < n && !visited[backward]) {
                q.push(backward);
                visited[backward] = 1;
            }
        }

        return false;
    }
};
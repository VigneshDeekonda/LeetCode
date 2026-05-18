class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        queue<int> que;
        que.push(0);
        visited[0] = true;

        int steps = 0;

        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                int curr = que.front();
                que.pop();

                if (curr == n - 1) return steps;
                int left = curr - 1;
                if (left >= 0 && !visited[left]) {
                    visited[left] = true;
                    que.push(left);
                }

                int right = curr + 1;
                if (right < n && !visited[right]) {
                    visited[right] = true;
                    que.push(right);
                }

        
                for (int idx : mp[arr[curr]]) {
                    if (!visited[idx]) {
                        visited[idx] = true;
                        que.push(idx);
                    }
                }

            
                mp.erase(arr[curr]);
            }

            steps++;
        }

        return -1;
    }
};

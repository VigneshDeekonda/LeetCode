/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 0;
        int maxSum = INT_MIN;
        int level = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            int sum = 0;

            for (int i = 0; i < len; i++) {
                TreeNode* t = q.front();
                q.pop();

                sum += t->val;

                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }

            level++;
        }

        return maxLevel;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *ritght) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
public:
    const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;

    // First DFS: calculate total sum
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    // Second DFS: try splitting at every node
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subSum = root->val + leftSum + rightSum;

        // Product if we cut above this subtree
        long long product = subSum * (totalSum - subSum);
        maxProd = max(maxProd, product);

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};
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
    long sum = 0, prod = 0;
    long dfs(TreeNode* root) {
        if(!root)
            return 0;
        long temp = root->val + dfs(root->left) + dfs(root->right);
        prod = max(prod, temp * (sum - temp));
        return temp;
    }

    int maxProduct(TreeNode* root) {
        sum = dfs(root);
        dfs(root);
        return prod % (int)(1e9 + 7);
    }
};

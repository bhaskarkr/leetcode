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
    void helper(TreeNode* root, int &ans, int level, int num) {
        num = (num << 1) | (root->val);
        if(!root->left && !root->right) {
            ans += num;
            return;
        }
        if(root->left)
            helper(root->left, ans, level + 1, num);
        if(root->right)
            helper(root->right, ans, level + 1, num);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        helper(root, ans, 0, 0);
        return ans;
    }
};

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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans, false);
        return ans;
    }
    
    void helper(TreeNode* root, int level, int &ans, bool leftLeaf) {
        if(!root)
            return;
        if(leftLeaf && !root->left && !root->right) {
            ans += root->val;
        }
        helper(root->left, level + 1, ans, true);
        helper(root->right, level + 1, ans, false);
    }
};

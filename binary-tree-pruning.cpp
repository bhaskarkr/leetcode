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
    TreeNode* pruneTree(TreeNode* root) {
        int ans = helper(root);
        return ans == 0 ? NULL : root;
    }
    
    int helper(TreeNode* root) {
        if(!root) 
            return 0;
        int curr = root->val;
        int left = helper(root->left);
        int right = helper(root->right);
        if(left == 0)
            root->left = NULL;
         if(right == 0)
            root->right = NULL;
        return curr + left + right;
    }
};

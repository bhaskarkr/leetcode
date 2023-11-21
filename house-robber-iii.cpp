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
    pair<int, int> helper(TreeNode* root) {
        if(!root)
            return {0, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        int included = left.first + right.first + root->val;
        int notIncluded = max(left.first, left.second) + max(right.first, right.second);
        return {notIncluded, included};
    }
    int rob(TreeNode* root) {
        auto ans = helper(root);
        return max(ans.first, ans.second);
    }
};

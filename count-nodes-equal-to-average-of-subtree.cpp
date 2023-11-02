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
    pair<int ,int> helper(TreeNode* root, int &ans) {
        if(!root)
            return {0, 0};
        auto left = helper(root->left, ans);
        auto right = helper(root->right, ans);
        pair<int, int> subtree = {left.first + right.first + root->val, left.second + right.second + 1};
        if(subtree.first / subtree.second == root->val)
            ans++;
        return subtree;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};

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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        helper(root, root, ans);
        return ans;
    }

    pair<int, int> helper(TreeNode* root, TreeNode* parent, int &ans) {
        if(!root) {
            return {0, 0};
        }
        auto left = helper(root->left, root, ans);
        auto right = helper(root->right, root, ans);
        ans = max(ans, left.first + right.second + 1);
        ans = max(ans, left.second + right.first + 1);
        int inc = 0;
        int dec = 0;
        if(root->val == parent->val + 1) {
            inc = max(left.first, right.first) + 1;
        }
        if(root->val == parent->val - 1) {
            dec = max(left.second, right.second) + 1;
        }
        return {inc, dec};
    }
};

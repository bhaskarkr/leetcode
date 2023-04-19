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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }

    int helper(TreeNode* root, int direction, int &ans) {
        if(!root)
            return 0;
        int left = helper(root->left, -1, ans);
        int right = helper(root->right, 1, ans);
        if(direction == -1) {
            ans = max(ans, right + 1);
            return right + 1;
        } else if(direction == 1){
            ans = max(ans, left + 1);
            return left + 1;
        }
        ans = max(ans, left);
        ans = max(ans, right);
        return 1;
    }
};

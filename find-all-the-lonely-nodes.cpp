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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        helper(root, false, ans);
        return ans;
    }

    void helper(TreeNode* root, bool single, vector<int> &ans) {
        if(!root)
            return;
        if(single) {
            ans.push_back(root->val);
        }
        single = false;
        if((root->left && !root->right) || (!root->left && root->right)) {
            single = true;
        }
        helper(root->left, single, ans);
        helper(root->right, single, ans);
    }
};

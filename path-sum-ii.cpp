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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root, ans, targetSum, {});
        return ans;
    }
    
    void helper(TreeNode* root, vector<vector<int>> &ans, int targetSum, vector<int> path) {
        if(!root) {
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;
        if(!root->left && !root->right) {
            if(targetSum == 0) {
                ans.push_back(path);
            }
            return;
        }
        helper(root->left, ans, targetSum, path);
        helper(root->right, ans, targetSum, path);
    }
};

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans = {};
        populateVector(root, ans);
        return ans;
    }
    
    int populateVector(TreeNode* root, vector<vector<int>>& ans) {
        if(!root)
            return 0;
        int index = max(populateVector(root->left, ans), populateVector(root->right, ans));
        if(ans.size() <= index)
            ans.push_back({});
        ans[index].push_back(root->val);
        return index+1;
    }
};

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
        vector<vector<int>> ans;
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode* root, vector<vector<int>> &ans) {
        if(!root)
            return 0;
        if(!root->left && !root->right) {
            if(ans.empty()) {
                ans.push_back({});
            }
            ans[0].push_back(root->val);
            return 0;
        }
        int l = helper(root->left, ans) + 1;
        int r = helper(root->right, ans) + 1;
        int maxDepth = max(l, r);
        if(ans.size() <= maxDepth) {
            ans.push_back({});
        }
        ans[maxDepth].push_back(root->val);
        return maxDepth;
    }
};

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        set<int> deleteSet(to_delete.begin(), to_delete.end());
        helper(root, ans, deleteSet, true);
        return ans;
    }
    
    TreeNode* helper(TreeNode* root, vector<TreeNode*>& ans, set<int> &deleteSet, bool isRoot) {
        if(!root)
            return root;
        bool deleted = false;
        if(deleteSet.find(root->val) != deleteSet.end()) {
            deleted = true;
        } else if(isRoot) {
            ans.push_back(root);
        }
        root->left = helper(root->left, ans, deleteSet, deleted);
        root->right = helper(root->right, ans, deleteSet, deleted);
        return deleted ? NULL : root;
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
    vector<TreeNode*> ans;
    unordered_set<int> s;
    TreeNode* helper(TreeNode* root, bool parentDelete) {
        if(!root)
            return root;
        if(s.find(root->val) != s.end()) 
            parentDelete = true;
        else {
            if(parentDelete)
                ans.push_back(root);
            parentDelete = false;
        }
        root->left = helper(root->left, parentDelete);
        root->right = helper(root->right, parentDelete);
        return parentDelete ? NULL : root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        s.insert(to_delete.begin(), to_delete.end());
        helper(root, true);
        return ans;
    }
};

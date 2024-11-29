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
    vector<int> ans;
    void topLeft(TreeNode* root) {
        if(!root or (!root->left and !root->right))
            return;
        ans.push_back(root->val);
        if(root->left) {
            topLeft(root->left);
        } else {
            topLeft(root->right);
        }
    }
    void topRight(TreeNode* root) {
        if(!root or (!root->left and !root->right))
            return;
        if(root->right) {
            topRight(root->right);
        } else {
            topRight(root->left);
        }
        ans.push_back(root->val);
    }

    void leaf(TreeNode* root) {
        if(!root)
            return;
        if(!root->left and !root->right)
            ans.push_back(root->val);
        leaf(root->left);
        leaf(root->right);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        ans.push_back(root->val);
        if(!root->left and !root->right)
            return ans;
        topLeft(root->left);
        leaf(root);
        topRight(root->right);
        return ans;
    }
};

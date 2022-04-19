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
    void recoverTree(TreeNode* root) {
        TreeNode* firstNode = NULL, *secondNode = NULL, *prev = new TreeNode(INT_MIN);
        helper(root, prev, firstNode, secondNode);
        swap(firstNode->val, secondNode->val);
    }
    
    void helper(TreeNode* root, TreeNode* &prev, TreeNode* &firstNode, TreeNode* &secondNode) {
        if(!root)
            return;
        helper(root->left, prev, firstNode, secondNode);
        if(root->val < prev->val && !firstNode) {
                firstNode = prev;
        }
        if(root->val < prev->val && firstNode) {
                secondNode = root;
        }
        prev = root;
        helper(root->right, prev, firstNode, secondNode);
    }
};

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot) || (root && (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)));
    }

    bool helper(TreeNode* root1, TreeNode* root2) {
        return (root1 == NULL && root2 == NULL) || ( root1 && root2 && root1->val == root2->val && helper(root1->left, root2->left) && helper(root1->right, root2->right));
    }
};

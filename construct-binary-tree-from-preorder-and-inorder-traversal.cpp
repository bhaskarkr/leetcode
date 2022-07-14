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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return helper(idx, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode* helper(int& idx, int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if(idx >= preorder.size() || start > end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        int mid = 0;
        for(int i = start; i <= end; i++) {
            if(inorder[i] == preorder[idx]) {
                mid = i;
                break;
            }
        }
        idx++;
        root->left = helper(idx, start, mid - 1, preorder, inorder);
        root->right = helper(idx, mid + 1, end, preorder, inorder);
        return root;
    }
};

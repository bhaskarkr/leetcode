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
    enum {NO_CAMERA = 0, HAS_CAMERA = 1, NOT_NEEDED = 2};
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        if(dfs(root, ans) == NO_CAMERA)
            ans++;
        return ans;
    }
    
    int dfs(TreeNode* root, int &ans) {
        if(!root)
            return NOT_NEEDED;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        if(l == NO_CAMERA || r == NO_CAMERA) {
            ans++;
            return HAS_CAMERA;
        }
        if(l == HAS_CAMERA || r == HAS_CAMERA) {
            return NOT_NEEDED;
        }
        return NO_CAMERA;
    }
};

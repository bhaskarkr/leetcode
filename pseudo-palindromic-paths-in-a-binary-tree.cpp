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
    int ans = 0;
    void helper(TreeNode* root, vector<int> &umap) {
        if(!root)
            return;
        umap[root->val]++;
        helper(root->left, umap);
        helper(root->right, umap);
        if(!root->left && !root->right) {
            int odd = 0;
            for(auto &v : umap)
                if(v % 2)
                    odd++;
            if(odd < 2)
                ans++;
        }
        umap[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> umap(10);
        helper(root, umap);
        return ans;
    }
};

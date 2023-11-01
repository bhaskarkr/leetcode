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
    int maxC; 
    unordered_map<int , int> umap;
    void  helper(TreeNode* root) {
        if(!root)
            return;
        umap[root->val]++;
        maxC = max(maxC, umap[root->val]);
        if(root->left)
            helper(root->left);
        if(root->right)
            helper(root->right);  
    }
    vector<int> findMode(TreeNode* root) {
        helper(root);
        vector<int> temp;
        for(auto [k, v] : umap) {
            if(v == maxC)
                temp.push_back(k);
        }
        return temp;
    }
};

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> umap;
        serializer(umap, root);
        vector<TreeNode*> ans;
        for(auto [k, v] : umap) {
            if(v.size() > 1) {
                ans.push_back(v[0]);
            }
        }
        return ans;
    }
    
    string serializer(unordered_map<string, vector<TreeNode*>> &umap, TreeNode* root) {
        if(!root)
            return "";
        string serializedSubtree = "("+(root->left ? serializer(umap, root->left) : "L")+to_string(root->val)+(root->right ? serializer(umap, root->right) : "R")+")";
        umap[serializedSubtree].push_back(root);
        return serializedSubtree;
    }
};

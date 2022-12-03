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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int l, int r) {
        vector<TreeNode*> ans;
        if(r < l) {
            ans.push_back(NULL);
            return ans;
        }
        for(int i = l; i <= r; i++) {
            vector<TreeNode*> leftTrees = helper(l, i - 1);
            vector<TreeNode*> rightTrees = helper(i + 1, r);
            for(auto left : leftTrees) {
                for(auto right : rightTrees) {
                    TreeNode* curr = new TreeNode(i, left, right);
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> Q;
        if(root)
            Q.push(root);
        while(!Q.empty()) {
            int nodes = Q.size(), count = Q.size();
            long sum = 0;
            while(count--) {
                auto node = Q.front();
                Q.pop();
                sum += node->val;
                if(node->left)
                    Q.push(node->left);
                if(node->right)
                    Q.push(node->right);
            }
            ans.push_back((sum*1.0)/nodes);
        }
        return ans;
    }
};

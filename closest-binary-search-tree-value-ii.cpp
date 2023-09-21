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
    priority_queue<pair<double, int>> pq;
    void helper(TreeNode* root,double target, int k) {
        if(!root)
            return;
        double diff = abs(target - root->val); 
        pq.push({diff, root->val});
        if(pq.size() > k)
            pq.pop();
        helper(root->left, target, k);
        helper(root->right, target, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        helper(root, target, k);
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

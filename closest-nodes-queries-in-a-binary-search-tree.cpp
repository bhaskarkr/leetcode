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
    int q = 0;
    int prev = -1;
    void helper(vector<vector<int>> &ans, int& index, TreeNode* root, vector<pair<int, int>>& queries) {
        if(!root)
            return;
        helper(ans, index, root->left, queries);
        if(queries.size() <= index)
            return;
        while(index < queries.size() && root->val >= queries[index].first) {
            if(root->val == queries[index].first)
                ans[queries[index].second] = {root->val, root->val};
            else
                ans[queries[index].second] = {prev, root->val};
            index++;
        }
        prev = root->val;
        helper(ans, index, root->right, queries);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int index = 0, n = queries.size();
        vector<vector<int>> ans(n);
        vector<pair<int, int>> q;
        for(int i = 0; i < n; i++)
            q.push_back({queries[i], i});
        sort(q.begin(), q.end());
        helper(ans, index, root, q);
        while(index < n)
            ans[q[index++].second] = {prev, -1};
        return ans;
    }
};

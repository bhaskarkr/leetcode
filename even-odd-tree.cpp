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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1;
        q.push(root);
        while(!q.empty()) {
            int c = q.size();
            int prev = INT_MAX;
            if(level % 2)
                prev = 0;
            while(c--) {
                auto curr = q.front();
                q.pop();
                if(level % 2) {
                    if(curr->val % 2 == 0 || curr->val <= prev)
                        return false;
                } else {
                    if(curr->val % 2 || curr->val >= prev)
                        return false;
                }
                prev = curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            level++;
        }
        return true;
    }
};

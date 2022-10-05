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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
            return new TreeNode(val, root, NULL);
        
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty() && depth != 1) {
            int levelSize = Q.size();
            depth--;
            while(levelSize--) {
                auto curr = Q.front();
                Q.pop();
                if(curr->left)
                    Q.push(curr->left);
                if(curr->right)
                    Q.push(curr->right);
                if(depth == 1) {
                    curr->left = new TreeNode(val, curr->left, NULL);
                    curr->right = new TreeNode(val, NULL, curr->right);
                }
            }
        }
        return root;
    }

};

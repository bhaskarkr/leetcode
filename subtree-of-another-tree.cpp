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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot) || (root && (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)));
    }

    bool helper(TreeNode* root1, TreeNode* root2) {
        return (root1 == NULL && root2 == NULL) || ( root1 && root2 && root1->val == root2->val && helper(root1->left, root2->left) && helper(root1->right, root2->right));
    }
};

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
    bool checker(TreeNode* root1, TreeNode* root2) {
        if(!root1 or !root2)
            return root1 == root2;
        return root1->val == root2->val and checker(root1->left, root2->left) and checker(root1->right, root2->right);
    }    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if(curr->val == subRoot->val and checker(curr, subRoot)) {
                return true;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return false;
    }
};

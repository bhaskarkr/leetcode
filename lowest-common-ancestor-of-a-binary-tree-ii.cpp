/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void helper(TreeNode* root) {
        if(!root)
            return;
        if(root->left) {
            helper(root->left);
            parent[root->left] = root;
        }
        if(root->right) {
            helper(root->right);
            parent[root->right] = root;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root);
        parent[root] = NULL;
        TreeNode* a = p, *b = q;
        if(p != root and !parent[p])
            return NULL;
        if(q != root and !parent[q])
            return NULL;
        while(a != b) {
            a = parent.find(a) != parent.end() ? parent[a] : q;
            b = parent.find(b) != parent.end() ? parent[b] : p;
        }
        return a;
    }
};

class Solution {
public:
    bool foundP = false;
    bool foundQ = false;
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        auto left = helper(root->left, p, q);
        auto right = helper(root->right, p, q);
        if(root == p) {
            foundP = true;
            return root;
        }
        if(root == q) {
            foundQ = true;
            return root;
        }
        return left ? (right ? root : left) : right;;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto res = helper(root, p, q);
        if(foundP and foundQ)
            return res;
        return NULL;
    }
};
